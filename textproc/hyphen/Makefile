# New ports collection makefile for:	hyphen
# Date created:		2011-06-18
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hyphen
PORTVERSION=	2.8.1
CATEGORIES=	textproc
MASTER_SITES=	SF/hunspell/Hyphen/${PORTVERSION:R}/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library for high quality hyphenation and justification

BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk

GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
USE_PERL5_BUILD=	yes

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
.for ALIAS in ${USALIASES}
PLIST_FILES+=	%%DATADIR%%/hyph_${ALIAS}.dic
.endfor

post-install:
.for ALIAS in ${USALIASES}
	${LN} -s hyph_en_US.dic ${DATADIR}/hyph_${ALIAS}.dic
.endfor

.include <bsd.port.mk>
