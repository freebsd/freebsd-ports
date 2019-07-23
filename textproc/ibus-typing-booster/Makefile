# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	ibus-typing-booster
PORTVERSION=	2.6.4
CATEGORIES=	textproc

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Faster typing by context sensitive completion

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/xdg/Menu.py:devel/py-xdg@${PY_FLAVOR}		\
		${PYTHON_LIBDIR}/lib-dynload/_sqlite3.so:databases/py-sqlite3@${PY_FLAVOR}
LIB_DEPENDS=	libibus-1.0.so:textproc/ibus	\
		libm17n.so:devel/m17n-lib
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/xdg/Menu.py:devel/py-xdg@${PY_FLAVOR}		\
		${PYTHON_SITELIBDIR}/dbus/bus.py:devel/py-dbus@${PY_FLAVOR}		\
		${PYTHON_SITELIBDIR}/hunspell.so:textproc/py-hunspell@${PY_FLAVOR}	\
		${LOCALBASE}/share/unicode/ucd/Index.txt:textproc/UCD			\
		${LOCALBASE}/share/unicode/cldr/readme.html:textproc/CLDR		\
		${PYTHON_LIBDIR}/lib-dynload/_sqlite3.so:databases/py-sqlite3@${PY_FLAVOR}
TEST_DEPENDS=	${LOCALBASE}/share/hunspell/de_DE.dic:german/hunspell		\
		${LOCALBASE}/share/hunspell/ko_KR.aff:korean/hunspell		\
		${LOCALBASE}/libexec/ibus-engine-m17n:textproc/ibus-m17n	\
		${LOCALBASE}/share/hunspell/en_US.aff:textproc/en-hunspell	\
		${LOCALBASE}/share/m17n/hi-inscript2.mim:devel/m17n-inscript2	\
		gmake:devel/gmake

USE_GITHUB=	yes
GH_ACCOUNT=	mike-fabian

USES=		autoreconf gettext gmake gnome iconv pathfix pkgconfig python:3.3+
USE_GNOME=	glib20 gtk30 pygobject3
GNU_CONFIGURE=	yes
NO_ARCH=	yes
INSTALLS_ICONS=	yes
GLIB_SCHEMAS=	org.freedesktop.ibus.engine.typing-booster.gschema.xml

TEST_TARGET=	check
TEST_ENV=	MAKE_CMD=${LOCALBASE}/bin/gmake LC_ALL=en_US.UTF-8

OPTIONS_DEFINE=	HUNSPELL
OPTIONS_DEFAULT=HUNSPELL

HUNSPELL_RUN_DEPENDS=	hunspell:textproc/hunspell

SPELL2FIX=	engine/hunspell_suggest.py setup/user_transliteration.py	\
		setup/user_transliteration.py
DATA2FIX=	setup/main.py engine/tabsqlitedb.py engine/main.py
PY2FIX=		setup/user_transliteration.py
M17N2FIX=	setup/main.py engine/itb_util.py engine/hunspell_table.py
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
		${WRKSRC}/engine/main.py
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
