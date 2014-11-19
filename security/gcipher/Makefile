# Created by: Shannon -jj Behrens <jjinux@yahoo.com>
# $FreeBSD$

PORTNAME=	gcipher
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	security gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple encryption tool

LICENSE=	BSD

USE_GNOME=	pygnome2
USES=		python

MAN1=		gcipher.1
LICENSE_FILES=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		'/^VERSION/s|=.*|= "${PORTVERSION}"|g ; \
		 /^GLADEDIR/s|=.*|= "${DATADIR}/lib"|g' ${WRKSRC}/src/Const.py
	@${REINPLACE_CMD} -e \
		's|/usr/bin/python|${SETENV} python|g ; \
		 s|^# sys.path.append|sys.path.append|g ; \
		 s|/usr/share/gcipher/lib|${DATADIR}/lib|' ${WRKSRC}/src/gcipher

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/src
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/src

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/gcipher ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gcipher.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/src/gcipher.desktop ${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib
	(cd ${WRKSRC}/src && \
		${FIND} . -name '*.glade' \
			-o -name '*.gladep' \
			-o -name '*.py' \
			-o -name '*.pyc' \
			-o -name '*.pyo' | \
		${CPIO} -pdm -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DATADIR}/lib)
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins
	(cd ${WRKSRC}/plugins && \
		${FIND} . -name '*.glade' \
			-o -name '*.gladep' \
			-o -name '*.py' | \
		${CPIO} -pdm -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DATADIR}/plugins)
	${FIND} ${STAGEDIR}${DATADIR} -type d | ${XARGS} ${CHMOD} a+rx
	${FIND} ${STAGEDIR}${DATADIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && \
		${INSTALL_DATA} CONTRIB README ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
