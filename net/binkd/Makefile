# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	binkd
PORTVERSION=	1.0.4
CATEGORIES=	net
MASTER_SITES=	ftp://happy.kiev.ua/pub/fidosoft/mailer/binkd/

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Fidonet TCP/IP mailer

USE_RC_SUBR=	binkd
GNU_CONFIGURE=	yes

USERS=		fido
GROUPS=		fido

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	AMIGA4D DOCS HTTPS
AMIGA4D_CONFIGUTE_WITH=	aso
HTTPS_CONFIGURE_WITH=	https

pre-configure:
	@${RM} -rf ${WRKSRC}/mkfls/unix/CVS
	@${CP} ${WRKSRC}/mkfls/unix/* ${WRKSRC}/
	@${CHMOD} a+x ${WRKSRC}/configure

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/binkd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/binkd.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/binkd.cfg ${STAGEDIR}${PREFIX}/etc/binkd.cfg.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/!README ${STAGEDIR}${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/!README.FIX ${STAGEDIR}${DOCSDIR}/README.FIX
	${INSTALL_DATA} ${WRKSRC}/!SRIF.TXT ${STAGEDIR}${DOCSDIR}/SRIF.TXT

.include <bsd.port.mk>
