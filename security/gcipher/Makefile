# Created by: Shannon -jj Behrens <jjinux@yahoo.com>
# $FreeBSD$

PORTNAME=	gcipher
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	security gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple encryption tool

LICENSE=	BSD

USE_GNOME=	pygnome2
USE_PYTHON=	yes

MAN1=		gcipher.1
LICENSE_FILES=	${WRKSRC}/LICENSE

NO_STAGE=	yes
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
	${INSTALL_SCRIPT} ${WRKSRC}/src/gcipher ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gcipher.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/src/gcipher.desktop ${PREFIX}/share/applications
	@${MKDIR} ${DATADIR}/lib
	@(cd ${WRKSRC}/src && \
		${FIND} . -name '*.glade' \
			-o -name '*.gladep' \
			-o -name '*.py' \
			-o -name '*.pyc' \
			-o -name '*.pyo' | \
		${CPIO} -pdm -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}/lib)
	@${MKDIR} ${DATADIR}/plugins
	@(cd ${WRKSRC}/plugins && \
		${FIND} . -name '*.glade' \
			-o -name '*.gladep' \
			-o -name '*.py' | \
		${CPIO} -pdm -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}/plugins)
	@${FIND} ${DATADIR} -type d | ${XARGS} ${CHMOD} a+rx
	@${FIND} ${DATADIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC} && \
		${INSTALL_DATA} CONTRIB README ${DOCSDIR})
.endif

.include <bsd.port.mk>
