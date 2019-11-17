# Created by: Craig Leres <leres@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spfmilter
PORTVERSION=	2.001
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	https://acme.com/software/spfmilter/

MAINTAINER=	leres@FreeBSD.org
COMMENT=	SPF milter for sendmail

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libmilter.so:mail/libmilter

USES=		cpe
GNU_CONFIGURE=	yes
CPE_VENDOR=	acme

OPTIONS_DEFAULT=	LIBSPF2
OPTIONS_RADIO=		SPF
OPTIONS_RADIO_SPF=	LIBSPF LIBSPF2

LIBSPF_LIB_DEPENDS=	libspf.so:mail/libspf
LIBSPF2_LIB_DEPENDS=	libspf2.so:mail/libspf2

LIBSPF_DESC=	Use the libspf Sender Policy Framework library
LIBSPF2_DESC=	Use the libspf2 Sender Policy Framework library

PLIST_FILES=	libexec/spfmilter \
		etc/rc.d/spfmilter \
		man/man8/spfmilter.8.gz \
		"@dir /var/run/spfmilter"

do-install:
	@${MKDIR} ${STAGEDIR}/var/run/spfmilter
	${INSTALL_PROGRAM} ${WRKSRC}/spfmilter ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/rc_scripts/freebsd ${STAGEDIR}${PREFIX}/etc/rc.d/spfmilter
	${INSTALL_MAN} ${WRKSRC}/spfmilter.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
