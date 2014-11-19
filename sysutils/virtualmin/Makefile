# $FreeBSD$

PORTNAME=	virtualmin
PORTVERSION=	4.12
CATEGORIES=	sysutils
MASTER_SITES=	http://download.webmin.com/download/virtualmin/
DISTNAME=	virtual-server-${PORTVERSION}.gpl
EXTRACT_SUFX=	.wbm.gz

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Virtual hosting management system based on webmin

RUN_DEPENDS=	${LOCALBASE}/lib/webmin/webmin-init:${PORTSDIR}/sysutils/webmin

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/virtual-server

post-extract:
	@${RM} -r ${WRKSRC}/images/.xvpics
	@${FIND} ${WRKSRC} -name "*.swp" -delete
	@${FIND} ${WRKSRC} -name "*.cgi" | ${XARGS} ${REINPLACE_CMD} -e "s@/usr/local/bin/perl@${PERL}@"
	@${FIND} ${WRKSRC} -name "*.bak" -delete
	@${FIND} ${WRKSRC} -name "*.cgi" | ${XARGS} ${CHMOD} 755
	@${FIND} ${WRKSRC} -type d -empty | ${XARGS} ${RMDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/webmin
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/webmin/virtual-server
	${CP} -r ${WRKSRC} ${STAGEDIR}${PREFIX}/lib/webmin

.include <bsd.port.mk>
