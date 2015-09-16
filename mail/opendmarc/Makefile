# Created by: Jaap Akkerhuis <jaap@NLnetLabs.nl>
# $FreeBSD$

PORTNAME=	opendmarc
PORTVERSION=	1.3.1
CATEGORIES=	mail security
MASTER_SITES=	SF/${PORTNAME} \
		SF/${PORTNAME}/Previous%20Releases

MAINTAINER=	freebsd@gushi.org
COMMENT=	DMARC library and milter implementation

LICENSE=		BSD3CLAUSE SENDMAIL
LICENSE_COMB=		multi

LICENSE_FILE_SENDMAIL=	${WRKSRC}/LICENSE.Sendmail
LICENSE_GROUPS_SENDMAIL=	FSF OSI
LICENSE_NAME_SENDMAIL=	Sendmail Open Source License
LICENSE_PERMS_SENDMAIL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

.if !exists( /usr/include/libmilter/mfapi.h )
BUILD_DEPENDS+=	${LOCALBASE}/include/libmilter/mfapi.h:${PORTSDIR}/mail/sendmail
CFLAGS+=	-I${LOCALBASE}/include
.endif

USES=		libtool shebangfix
SHEBANG_FILES=	reports/opendmarc-expire.in \
		reports/opendmarc-import.in \
		reports/opendmarc-params.in \
		reports/opendmarc-reports.in

USE_RC_SUBR=	opendmarc
USE_LDCONFIG=	yes

GNU_CONFIGURE=		yes

PORTDOCS=	*

OPTIONS_DEFINE=	SPF
OPTIONS_DEFAULT=	SPF
SPF_DESC=	Include direct SPF checking support

SPF_BUILD_DEPENDS+=	libspf2>=1.2.5:${PORTSDIR}/mail/libspf2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSPF}
CONFIGURE_ARGS+=	--with-spf --with-spf2-include=${LOCALBASE}/include/spf2 --with-spf2-lib=${LOCALBASE}/lib
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/mail
	${INSTALL_DATA} \
		${WRKSRC}/opendmarc/opendmarc.conf.sample ${STAGEDIR}${PREFIX}/etc/mail
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libopendmarc.so.2

.include <bsd.port.mk>
