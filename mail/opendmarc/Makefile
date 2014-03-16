# Created by: Jaap Akkerhuis <jaap@NLnetLabs.nl>
# $FreeBSD$

PORTNAME=	opendmarc
PORTVERSION=	1.2.0
CATEGORIES=	mail security
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME} \
			${PORTNAME}/Previous%20Releases

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	DMARC library and milter implementation

LICENSE=		BSD3CLAUSE SENDMAIL
LICENSE_COMB=		multi

LICENSE_FILE_SENDMAIL=	${WRKSRC}/LICENSE.Sendmail
LICENSE_GROUPS_SENDMAIL=	FSF OSI
LICENSE_NAME_SENDMAIL=	Sendmail Open Source License
LICENSE_PERMS_SENDMAIL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		shebangfix
SHEBANG_FILES=	reports/opendmarc-expire.in \
		reports/opendmarc-import.in \
		reports/opendmarc-params.in \
		reports/opendmarc-reports.in

USE_RC_SUBR=	opendmarc
USE_LDCONFIG=	yes

GNU_CONFIGURE=		yes

PORTDOCS=	*

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/mail
	${INSTALL_DATA} \
		${WRKSRC}/opendmarc/opendmarc.conf.sample ${STAGEDIR}${PREFIX}/etc/mail
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libopendmarc.so.1

.include <bsd.port.mk>
