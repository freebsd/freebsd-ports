# New ports collection makefile for:	argus
# Date created:		26 November 1998
# Whom:			Jonathan Hanna <jhanna@home.com>
#
# $FreeBSD$
#

PORTNAME=	argus
PORTVERSION=	2.0.6
PORTREVISION=	2
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://qosient.com/argus/src/ \
		ftp://qosient.com/pub/argus/src/

MAINTAINER=	5u623l20@gmail.com
COMMENT=	A generic IP network transaction auditing tool


DEPRECATED=	Using of this branch of argus is discouraged. Please migrate to net-mgmt/argus3
EXPIRATION_DATE=2013-02-05

PORTSCOUT=	ignore:1	# This is the last version of 2.0.X branch

CONFLICTS=	argus-3* argus-sasl-3*

.if defined(WITH_SASL)
LIB_DEPENDS+=	sasl2:${PORTSDIR}/security/cyrus-sasl2
.endif
RUN_DEPENDS=	${LOCALBASE}/bin/ragrep:${PORTSDIR}/net-mgmt/argus-clients

USE_BISON=	build
GNU_CONFIGURE=	true
CONFIGURE_ARGS=	--exec-prefix=${PREFIX}
.if defined(WITH_SASL)
CONFIGURE_ARGS+= --with-sasl=${PREFIX}
.endif

DOCSDIR?=       ${PREFIX}/share/doc/argus-2.0

MAN5=		argus.5 argus.conf.5
MAN8=		argus.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/argus_bpf ${PREFIX}/sbin/argus
	${MKDIR} ${PREFIX}/argus/archive
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/html/man
.for i in  doc/html/man/*.html
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}/html/man
.endfor
.endif
.if !defined(NOMAN)
.for i in ${MAN5}
	${INSTALL_DATA} ${WRKSRC}/man/man5/$i ${PREFIX}/man/man5
.endfor
.for i in ${MAN8}
	${INSTALL_DATA} ${WRKSRC}/man/man8/$i ${PREFIX}/man/man8
.endfor
.endif

.include <bsd.port.mk>
