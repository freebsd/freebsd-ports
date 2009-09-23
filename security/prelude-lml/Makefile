# New ports collection makefile for:	prelude-lml
# Date created:			Sun Aug 4 19:31:17 CEST 2002
# Whom:				Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$

PORTNAME=	prelude-lml
PORTVERSION=	0.9.15
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-ids.com/download/releases/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME} ${PORTNAME}/old

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Prelude Network Intrusion Detection System Log Monitoring Lackey

LIB_DEPENDS+=	prelude.20:${PORTSDIR}/security/libprelude \
		pcre.0:${PORTSDIR}/devel/pcre

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_RC_SUBR=	prelude-lml.sh
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

.include <bsd.port.pre.mk>

.if defined(WITH_FAM)
USE_FAM=	yes
CONFIGURE_ARGS+=	--enable-fam
.else
CONFIGURE_ARGS+=	--disable-fam
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/prelude-lml/prelude-lml.conf ]; then \
	   ${CP} -p ${PREFIX}/etc/prelude-lml/prelude-lml.conf-dist \
	      ${PREFIX}/etc/prelude-lml/prelude-lml.conf ; \
	fi
	@if [ ! -f ${PREFIX}/etc/prelude-lml/plugins.rules ]; then \
	   ${CP} -p ${PREFIX}/etc/prelude-lml/plugins.rules-dist \
	      ${PREFIX}/etc/prelude-lml/plugins.rules ; \
	fi

.include <bsd.port.post.mk>
