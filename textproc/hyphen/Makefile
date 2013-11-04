# $FreeBSD$

PORTNAME=	hyphen
PORTVERSION=	2.8.6
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/hunspell/Hyphen/${PORTVERSION:R}/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library for high quality hyphenation and justification

BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk

GNU_CONFIGURE=	yes
USES=	pathfix perl5 shebangfix
USE_LDCONFIG=	yes
SHEBANG_FILES=	substrings.pl

CONFIGURE_ENV+=	ac_cv_prog_AWK=gawk

PLIST_FILES=	bin/substrings.pl \
		include/hyphen.h \
		lib/libhyphen.a \
		lib/libhyphen.la \
		lib/libhyphen.so \
		lib/libhyphen.so.2 \
		%%DATADIR%%/hyph_en_US.dic
PLIST_DIRSTRY=	%%DATADIR%%

USALIASES=	en_AG en_AU en_BS en_BW en_BZ en_CA en_DK en_GB en_GH en_HK \
		en_IE en_IN en_JM en_NA en_NZ en_PH en_SG en_TT en_ZA en_ZW

CONFIGURE_ENV+=	ac_cv_prog_AWK=gawk
.for ALIAS in ${USALIASES}
PLIST_FILES+=	%%DATADIR%%/hyph_${ALIAS}.dic
.endfor

post-install:
.for ALIAS in ${USALIASES}
	${LN} -s hyph_en_US.dic ${STAGEDIR}${DATADIR}/hyph_${ALIAS}.dic
.endfor
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libhyphen.so.2

.include <bsd.port.mk>
