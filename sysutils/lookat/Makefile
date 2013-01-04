# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	lookat
PORTVERSION=	1.4.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.wagemakers.be/uploads/d9/2a/d92a52ea9fdfb96d1196005e0fa60fca/
DISTNAME=	${PORTNAME}_bekijk-${PORTVERSION}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Program to view Un*x text files and manual pages

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		lookat.1

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} 's|/etc/lookat.conf|${PREFIX}&|g' \
		${WRKSRC}/${PORTNAME}.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/lookat ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/lookat.1 ${PREFIX}/man/man1
	@${INSTALL_DATA} ${WRKSRC}/lookat.conf.default \
		${PREFIX}/etc/lookat.conf.sample
	@if [ ! -f ${PREFIX}/etc/lookat.conf ]; then \
		${CP} -p ${PREFIX}/etc/lookat.conf.sample ${PREFIX}/etc/lookat.conf ; \
	fi

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
