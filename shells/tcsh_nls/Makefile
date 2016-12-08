# Created by: Hajimu UMEMOTO <ume@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tcsh_nls
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Misc NLS catalogs for tcsh which requires libiconv

USES=		iconv
NO_BUILD=	yes

PLIST_FILES=	share/nls/de_AT.UTF-8/tcsh.cat \
		share/nls/de_CH.UTF-8/tcsh.cat \
		share/nls/de_DE.UTF-8/tcsh.cat \
		share/nls/el_GR.UTF-8/tcsh.cat \
		share/nls/es_ES.UTF-8/tcsh.cat \
		share/nls/et_EE.UTF-8/tcsh.cat \
		share/nls/fi_FI.UTF-8/tcsh.cat \
		share/nls/fr_BE.UTF-8/tcsh.cat \
		share/nls/fr_CA.UTF-8/tcsh.cat \
		share/nls/fr_CH.UTF-8/tcsh.cat \
		share/nls/fr_FR.UTF-8/tcsh.cat \
		share/nls/it_CH.UTF-8/tcsh.cat \
		share/nls/it_IT.UTF-8/tcsh.cat \
		share/nls/ja_JP.SJIS/tcsh.cat \
		share/nls/ja_JP.UTF-8/tcsh.cat \
		share/nls/ru_RU.CP1251/tcsh.cat \
		share/nls/ru_RU.CP866/tcsh.cat \
		share/nls/ru_RU.ISO8859-5/tcsh.cat \
		share/nls/ru_RU.UTF-8/tcsh.cat \
		share/nls/uk_UA.ISO8859-5/tcsh.cat \
		share/nls/uk_UA.UTF-8/tcsh.cat

NLS_CATALOGS=	de_DE.ISO8859-1:de_AT.UTF-8 \
		de_DE.ISO8859-1:de_CH.UTF-8 \
		de_DE.ISO8859-1:de_DE.UTF-8 \
		el_GR.ISO8859-7:el_GR.UTF-8 \
		es_ES.ISO8859-1:es_ES.UTF-8 \
		et_EE.ISO8859-15:et_EE.UTF-8 \
		fi_FI.ISO8859-1:fi_FI.UTF-8 \
		fr_FR.ISO8859-1:fr_BE.UTF-8 \
		fr_FR.ISO8859-1:fr_CA.UTF-8 \
		fr_FR.ISO8859-1:fr_CH.UTF-8 \
		fr_FR.ISO8859-1:fr_FR.UTF-8 \
		it_IT.ISO8859-1:it_CH.UTF-8 \
		it_IT.ISO8859-1:it_IT.UTF-8 \
		ja_JP.eucJP:ja_JP.SJIS \
		ja_JP.eucJP:ja_JP.UTF-8 \
		ru_RU.KOI8-R:ru_RU.CP1251 \
		ru_RU.KOI8-R:ru_RU.CP866 \
		ru_RU.KOI8-R:ru_RU.ISO8859-5 \
		ru_RU.KOI8-R:ru_RU.UTF-8 \
		uk_UA.KOI8-U:uk_UA.ISO8859-5 \
		uk_UA.KOI8-U:uk_UA.UTF-8 \

do-install:
	@for i in ${NLS_CATALOGS}; do \
		${LN} -sf /usr/share/nls/$${i%%:*}/tcsh.cat \
			${STAGEDIR}${PREFIX}/share/nls/$${i##*:}/tcsh.cat; \
	done

.include <bsd.port.mk>
