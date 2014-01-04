# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	prelude-lml
PORTVERSION=	1.0.1
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	https://www.prelude-ids.org/attachments/download/242/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Prelude Network Intrusion Detection System Log Monitoring Lackey

LIB_DEPENDS=	icuuc:${PORTSDIR}/devel/icu \
		pcre:${PORTSDIR}/devel/pcre \
		gmp:${PORTSDIR}/math/gmp \
		gnutls:${PORTSDIR}/security/gnutls \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		gpg-error:${PORTSDIR}/security/libgpg-error \
		prelude:${PORTSDIR}/security/libprelude \
		nettle:${PORTSDIR}/security/nettle \
		p11-kit:${PORTSDIR}/security/p11-kit

USE_GMAKE=	yes
USE_AUTOTOOLS=	libltdl
GNU_CONFIGURE=	yes
USE_RC_SUBR=	prelude-lml
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
USES=		charsetfix gettext iconv pkgconfig

OPTIONS_DEFINE=	FAM
FAM_CONFIGURE_ENABLE=	fam
FAM_USES=	fam

NO_STAGE=	yes

post-install:
	@if [ ! -f ${PREFIX}/etc/prelude-lml/prelude-lml.conf ]; then \
	   ${CP} -p ${PREFIX}/etc/prelude-lml/prelude-lml.conf-dist \
	      ${PREFIX}/etc/prelude-lml/prelude-lml.conf ; \
	fi
	@if [ ! -f ${PREFIX}/etc/prelude-lml/plugins.rules ]; then \
	   ${CP} -p ${PREFIX}/etc/prelude-lml/plugins.rules-dist \
	      ${PREFIX}/etc/prelude-lml/plugins.rules ; \
	fi

.include <bsd.port.mk>
