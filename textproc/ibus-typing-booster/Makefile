# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	ibus-typing-booster
PORTVERSION=	1.5.34
CATEGORIES=	textproc

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Faster typing by context sensitive completion

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/xdg/Menu.py:devel/py-xdg@${PY_FLAVOR}		\
		${PYTHON_SITELIBDIR}/gi/_gi.so:devel/py-gobject3@${PY_FLAVOR}	\
		${PYTHON_LIBDIR}/lib-dynload/_sqlite3.so:databases/py-sqlite3@${PY_FLAVOR}
LIB_DEPENDS=	libibus-1.0.so:textproc/ibus	\
		libm17n.so:devel/m17n-lib
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/xdg/Menu.py:devel/py-xdg@${PY_FLAVOR}		\
		${PYTHON_SITELIBDIR}/dbus/bus.py:devel/py-dbus@${PY_FLAVOR}		\
		${PYTHON_SITELIBDIR}/hunspell.so:textproc/py-hunspell@${PY_FLAVOR}	\
		${PYTHON_SITELIBDIR}/gi/_gi.so:devel/py-gobject3@${PY_FLAVOR}	\
		${LOCALBASE}/share/unicode/ucd/Index.txt:textproc/UCD	\
		${LOCALBASE}/share/unicode/cldr/readme.html:textproc/CLDR\
		${PYTHON_LIBDIR}/lib-dynload/_sqlite3.so:databases/py-sqlite3@${PY_FLAVOR}
TEST_DEPENDS=	${LOCALBASE}/share/hunspell/de_DE.dic:german/hunspell	\
		${LOCALBASE}/share/hunspell/ko_KR.aff:korean/hunspell	\
		${LOCALBASE}/share/hunspell/en_US.aff:textproc/en-hunspell

USE_GITHUB=	yes
GH_ACCOUNT=	mike-fabian

USES=		autoreconf gettext gmake iconv pathfix pkgconfig python:3.3+
GNU_CONFIGURE=	yes
NO_ARCH=	yes
TEST_TARGET=	check

OPTIONS_DEFINE=	HUNSPELL
OPTIONS_DEFAULT=HUNSPELL

HUNSPELL_RUN_DEPENDS=	hunspell:textproc/hunspell

SPELL2FIX=	engine/hunspell_suggest.py setup/user_transliteration.py	\
		setup/user_transliteration.py
DATA2FIX=	setup/main.py engine/tabsqlitedb.py engine/main.py
PY2FIX=		setup/user_transliteration.py
M17N2FIX=	setup/main.py
SHR2FIX=	engine/tabsqlitedb.py engine/itb_util.py engine/itb_emoji.py	\
		engine/hunspell_table.py engine/main.py setup/user_transliteration.py
COMP2DEL=	engine/Makefile setup/Makefile

pre-configure:
.for f in ${SPELL2FIX}
	${REINPLACE_CMD} -e 's|/usr/share/myspell|${LOCALBASE}/share/hunspell|'	\
		${WRKSRC}/${f}
.endfor
.for f in ${PY2FIX}
	${REINPLACE_CMD} -e 's|/usr/bin/python3| ${PYTHON_CMD}|' ${WRKSRC}/${f}
.endfor
.for f in ${DATA2FIX}
	${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' ${WRKSRC}/${f}
.endfor
.for f in ${M17N2FIX}
	${REINPLACE_CMD} -e 's|/usr/share/m17n|${LOCALBASE}/share/m17n|'	\
		${WRKSRC}/${f}
.endfor
	${REINPLACE_CMD} -e 's|/usr/libexec|${PREFIX}/libexec|'	\
		${WRKSRC}/hunspell-tables/*.conf ${WRKSRC}/hunspell-tables/template.txt
.for f in ${SHR2FIX}
	${REINPLACE_CMD} -e 's|/usr/share/ibus-typing-booster|${DATADIR}|'	\
		-e 's|/usr/share|${LOCALBASE}/share|' ${WRKSRC}/${f}
.endfor

post-configure:
.for f in ${COMP2DEL}
	${SED} -i.orig -e '/if test -n "\$$\$$dlist"/,/^	else :; fi$$/ d'	\
		${WRKSRC}/${f}
.endfor

post-install:
	(cd ${STAGEDIR}${PREFIX} \
	&& ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
	-d ${PREFIX} -f ${DATADIR:S;${PREFIX}/;;}	\
	&& ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
	-d ${PREFIX} -f ${DATADIR:S;${PREFIX}/;;})

.include <bsd.port.mk>
