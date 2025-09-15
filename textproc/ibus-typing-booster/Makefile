PORTNAME=	ibus-typing-booster
PORTVERSION=	2.27.74
CATEGORIES=	textproc

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Faster typing by context sensitive completion
WWW=		https://mike-fabian.github.io/ibus-typing-booster/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${PY_FLAVOR}		\
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
LIB_DEPENDS=	libibus-1.0.so:textproc/ibus	\
		libm17n.so:devel/m17n-lib
RUN_DEPENDS=	CLDR>0:textproc/CLDR	\
		UCD>0:textproc/UCD	\
		${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${PY_FLAVOR}		\
		${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR}		\
		${PYTHON_PKGNAMEPREFIX}rapidfuzz>0:devel/py-rapidfuzz@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}hunspell>0:textproc/py-hunspell@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}pycountry>0:textproc/py-pycountry@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
TEST_DEPENDS=	${LOCALBASE}/share/hunspell/cs_CZ.dic:textproc/cs-hunspell	\
		${LOCALBASE}/share/hunspell/de_DE.dic:german/hunspell		\
		${LOCALBASE}/share/hunspell/en_US.aff:textproc/en-hunspell	\
		${LOCALBASE}/share/hunspell/es_ES.dic:textproc/es-hunspell	\
		${LOCALBASE}/share/hunspell/it_IT.dic:textproc/it-hunspell	\
		${LOCALBASE}/share/hunspell/ko_KR.aff:korean/hunspell		\
		${LOCALBASE}/share/hunspell/sv_SE.dic:textproc/sv-hunspell	\
		${LOCALBASE}/libexec/ibus-engine-m17n:textproc/ibus-m17n	\
		${LOCALBASE}/share/m17n/hi-inscript2.mim:devel/m17n-inscript2	\
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}	\
		gmake:devel/gmake

USE_GITHUB=	yes
GH_ACCOUNT=	mike-fabian

USES=		autoreconf desktop-file-utils gettext gmake gnome iconv pathfix	\
		pkgconfig python shebangfix
SHEBANG_FILES=	engine/emoji-picker.in engine/ibus-engine-typing-booster.in	\
		setup/ibus-setup-typing-booster.in
SHEBANG_LANG=	sh
sh_OLD_CMD=	/usr/bin/sh
sh_CMD=		${SH}
USE_GNOME=	glib20 gtk30 pygobject3
USE_LOCALE=	en_US.UTF-8
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libexecdir=${PREFIX}/libexec
NO_ARCH=	yes
GLIB_SCHEMAS=	org.freedesktop.ibus.engine.typing-booster.gschema.xml

TEST_TARGET=	check
TEST_ENV=	${MAKE_ENV} \
		IBUS_TYPING_BOOSTER_DEBUG_LEVEL=1

OPTIONS_DEFINE=	HUNSPELL
OPTIONS_DEFAULT=HUNSPELL

HUNSPELL_RUN_DEPENDS=	hunspell:textproc/hunspell

SPELL2FIX=	engine/itb_util.py setup/user_transliteration.py
SHR2FIX=	engine/itb_sound.py ${GLIB_SCHEMAS}
XML2FIX=	org.freedesktop.ibus.engine.typing_booster.metainfo.xml.in	\
		org.freedesktop.ibus.engine.typing_booster.emoji_picker.metainfo.xml.in
X11LOC2FIX=	engine/itb_util.py tests/test_compose_sequences.py tests/test_itb.py
COMP2DEL=	engine/Makefile setup/Makefile

pre-configure:
.for f in ${SPELL2FIX}
	${REINPLACE_CMD} -e 's|/usr/share/myspell|${LOCALBASE}/share/hunspell|'	\
		${WRKSRC}/${f}
.endfor
	${FIND} ${WRKSRC} -name "*.py" | ${XARGS}	\
	${REINPLACE_CMD} -e 's|/usr/bin/python3| ${PYTHON_CMD}|'
.for f in ${XML2FIX}
	${REINPLACE_CMD} -e 's|/usr/libexec|${PREFIX}/libexec|'	${WRKSRC}/${f}
.endfor
.for f in ${SHR2FIX} ${XML2FIX}
	${REINPLACE_CMD} -e 's|/usr/share/ibus-typing-booster|${DATADIR}|'	\
		-e 's|/usr/share|${LOCALBASE}/share|' ${WRKSRC}/${f}
.endfor
	${REINPLACE_CMD} -e 's|/usr/share/unicode|${LOCALBASE}/share/unicode|'	\
		${WRKSRC}/engine/itb_emoji.py
.for f in ${X11LOC2FIX}
	${REINPLACE_CMD} -e 's|/usr/share/X11/locale|${LOCALBASE}/lib/X11/locale|'	\
		${WRKSRC}/${f}
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
