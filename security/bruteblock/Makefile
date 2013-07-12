# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	bruteblock
PORTVERSION=	0.0.5
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://samm.kiev.ua/bruteblock/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Software for blocking bruteforce attacks with ipfw

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
MAKE_JOBS_SAFE=	yes

USE_RC_SUBR=	bruteblockd
MAN8=		bruteblock.8

CONFDIR=	${PREFIX}/etc/${PORTNAME}

PORTDOCS=	FAQ README CHANGES

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bruteblock ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/bruteblockd ${PREFIX}/sbin/
	${MKDIR} ${PREFIX}/etc/bruteblock
.for file in ssh proftpd
	${INSTALL_DATA} ${WRKSRC}/etc/${file}.conf ${CONFDIR}/${file}.conf.dist
	if [ ! -f ${CONFDIR}/${file}.conf ]; then \
		${INSTALL_DATA} ${CONFDIR}/${file}.conf.dist ${CONFDIR}/${file}.conf; \
	fi
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/bruteblock.8 ${PREFIX}/man/man8/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/FAQ ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/doc/README ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/doc/CHANGES ${DOCSDIR}/
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
