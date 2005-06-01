# New ports collection makefile for:	utf8locale
# Date created:		29 June 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	utf8locale
PORTVERSION=	040319
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES= 	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~perky/distfiles/
MASTER_SITE_SUBDIR=	perky

MAINTAINER=	perky@FreeBSD.org
COMMENT=	UTF-8 locales support

USE_REINPLACE=	yes

LANGS=		af_ZA be_BY bg_BG ca_ES cs_CZ da_DK de_AT de_CH de_DE el_GR \
		en_AU en_CA en_IE en_GB en_NZ en_US es_ES et_EE fi_FI fr_BE \
		fr_CA fr_CH fr_FR hr_HR hu_HU hy_AM is_IS it_CH it_IT ja_JP \
		kk_KZ ko_KR lt_LT nl_BE nl_NL no_NO pl_PL pt_BR pt_PT ro_RO \
		ru_RU sk_SK sl_SI sr_YU sv_SE tr_TR uk_UA zh_CN zh_HK zh_TW
BASELOCALEDIR=	${DESTDIR}/usr/share/locale
PLIST_SUB=	BASELOCALEDIR=${BASELOCALEDIR} \
		LANGS="${LANGS}"
PLIST=		${WRKDIR}/pkg-plist

.include <bsd.port.pre.mk>

_HAVE_SWIDTH!=	${GREP} _CTYPE_SW ${DESTDIR}/usr/include/ctype.h 2>/dev/null \
		|| ${TRUE}
.if empty(_HAVE_SWIDTH)
PKGNAMESUFFIX=	-without-swidth
.endif

.if ${OSVERSION} >= 502110
IGNORE=		is already in your base system
.endif

post-patch:
	${REINPLACE_CMD} -e 's,\(rm -rf.*/\)\*\(/LC_MESS\),\1*.UTF-8\2,g' \
		${WRKSRC}/msgdef/Makefile
.if empty(_HAVE_SWIDTH)
	${REINPLACE_CMD} -e 's,^SWIDTH.*$$,,g' \
		-e 's,UTF-8,UTF2,g' ${WRKSRC}/mklocale/la_LN.UTF-8.src
.endif

pre-install:
	-@${RM} -f ${PLIST}
.for lang in ${LANGS}
.for cate in LC_COLLATE LC_CTYPE LC_MESSAGES LC_MONETARY LC_NUMERIC LC_TIME
	@${ECHO} "share/locale/${lang}.UTF-8/${cate}" >> ${PLIST}
.endfor
	@${ECHO} "@dirrm share/locale/${lang}.UTF-8" >> ${PLIST}
.endfor
	@${CAT} ${.CURDIR}/pkg-plist >> ${PLIST}

post-install:
.for lang in ${LANGS}
	-${LN} -sf ${PREFIX}/share/locale/${lang}.UTF-8 \
		${BASELOCALEDIR}/${lang}.UTF-8
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
