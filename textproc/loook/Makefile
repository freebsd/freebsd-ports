PORTNAME=	loook
PORTVERSION=	0.9.1
CATEGORIES=	textproc
MASTER_SITES=	http://mechtilde.de/Loook/Downloads/
DIST_SUBDIR=	python

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Simple Python tool that search in LibreOffice/OpenOffice files
WWW=		https://mechtilde.de/Loook/

LICENSE=	GPLv2+

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>=0:x11-toolkits/py-tkinter@${PY_FLAVOR}

USES=		python gettext-tools:build desktop-file-utils

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/${PORTNAME} \
		share/applications/loook.desktop \
		share/locale/cs/LC_MESSAGES/loook.mo \
		share/locale/de/LC_MESSAGES/loook.mo \
		share/locale/en/LC_MESSAGES/loook.mo \
		share/locale/es/LC_MESSAGES/loook.mo \
		share/locale/fr/LC_MESSAGES/loook.mo \
		share/locale/it/LC_MESSAGES/loook.mo \
		share/locale/nl/LC_MESSAGES/loook.mo \
		share/locale/pt_BR/LC_MESSAGES/loook.mo \
		share/man/man1/loook.1.gz \
		share/man/de/man1/loook.1.gz \
		share/pixmaps/loook.png \

LCMESSAGES=	cs de en es fr it nl pt_BR

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python3|${PYTHON_CMD}|' \
		-e 's|/usr/share/locale/|${PREFIX}/share/locale/|' \
		${WRKSRC}/${PORTNAME}.py
	@${MV} -v ${WRKSRC}/loook.pt-br.po ${WRKSRC}/loook.pt_BR.po

do-build:
.for i in ${LCMESSAGES}
	msgfmt --check --output-file=${WRKSRC}/loook.${i}.mo ${WRKSRC}/loook.${i}.po
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	-${MKDIR} ${STAGEDIR}${PREFIX}/share/man/de/man1
	${INSTALL_MAN} ${WRKSRC}/man/loook.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL_MAN} ${WRKSRC}/man/de/loook.1 \
		${STAGEDIR}${PREFIX}/share/man/de/man1/
	${INSTALL_DATA} ${WRKSRC}/loook.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/loook.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
.for i in ${LCMESSAGES}
	${INSTALL_DATA} \
		${WRKSRC}/loook.${i}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${i}/LC_MESSAGES/loook.mo
.endfor

.include <bsd.port.mk>
