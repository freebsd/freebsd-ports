# Ports collection makefile for:  nmap-i18n-man
# Date created:			  2006-02-19
# Whom:				  Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#

PORTNAME=	nmap-i18n-man
PORTVERSION=	4.68.20080803
CATEGORIES=	security ipv6
MASTER_SITES=	http://nmap.org/data/man-xlate/ \
		http://mirror.roe.ch/dist/${PORTNAME}/${PORTVERSION}/
DISTFILES=	${LANG_MAP:C/^/nmap-/:C/=[^=]*$/.1/}	# OPTIONS based
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	daniel@roe.ch
COMMENT=	Translated manual pages for nmap

BUILD_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv

MAN1=		nmap.1
MANLANG=	${LANG_MAP:C/^[^=]*=//}			# OPTIONS based

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKDIR}
NO_WRKSUBDIR=	yes

OPTIONS=	MAN_ES "Spanish" On \
		MAN_FR "French" On \
		MAN_HR "Croatian" On \
		MAN_IT "Italian" On \
		MAN_JP "Japanese" On \
		MAN_PL "Polish" On \
		MAN_PT_BR "Portuguese (Brazil)" On \
		MAN_PT_PT "Portuguese (Portugal)" On \
		MAN_RO "Romanian" On \
		MAN_SK "Slovak" On \
		MAN_ZH "Chinese" On

.include <bsd.port.pre.mk>

LANG_MAP=
.if !defined(WITHOUT_MAN_ES)
LANG_MAP+=	es=es.ISO8859-1
.endif
.if !defined(WITHOUT_MAN_FR)
LANG_MAP+=	fr=fr.ISO8859-1
.endif
.if !defined(WITHOUT_MAN_HR)
LANG_MAP+=	hr=hr.ISO8859-2
.endif
.if !defined(WITHOUT_MAN_IT)
LANG_MAP+=	it=it.ISO8859-1
.endif
.if !defined(WITHOUT_MAN_JP)
LANG_MAP+=	jp=jp.eucJP
.endif
.if !defined(WITHOUT_MAN_PL)
LANG_MAP+=	pl=pl.ISO8859-2
.endif
.if !defined(WITHOUT_MAN_PT_BR)
LANG_MAP+=	pt-br=pt_BR.ISO8859-1
.endif
.if !defined(WITHOUT_MAN_PT_PT)
LANG_MAP+=	pt-pt=pt.ISO8859-1
.endif
.if !defined(WITHOUT_MAN_RO)
LANG_MAP+=	ro=ro.ISO8859-2
.endif
.if !defined(WITHOUT_MAN_SK)
LANG_MAP+=	sk=sk.ISO8859-2
.endif
.if !defined(WITHOUT_MAN_ZH)
LANG_MAP+=	zh=zh.Big5
.endif

ICONV?=${LOCALBASE}/bin/iconv

do-build:
	@for token in ${LANG_MAP}; do \
		lang="`expr $${token} : '\([^=]*\)'`"; \
		locale="`expr $${token} : '.*=\([^=]*\)'`"; \
		charset="`expr $${locale} : '[^.]*\.\([^.]*\)'`"; \
		${ECHO_CMD} Converting nmap-$${lang}.1 from UTF-8 to $${charset}; \
		${ICONV} -c -f UTF-8 -t $${charset} ${WRKSRC}/nmap-$${lang}.1 \
			> ${WRKSRC}/nmap-$${lang}.1.$${charset} || true; \
	done

do-install:
	@for token in ${LANG_MAP}; do \
		lang="`expr $${token} : '\([^=]*\)'`"; \
		locale="`expr $${token} : '.*=\([^=]*\)'`"; \
		charset="`expr $${locale} : '[^.]*\.\([^.]*\)'`"; \
		${MKDIR} ${MAN1PREFIX}/man/$${locale}/man1; \
		${ECHO_CMD} Installing man/$${locale}/man1/nmap.1; \
		${INSTALL_MAN} ${WRKSRC}/nmap-$${lang}.1.$${charset} \
			${MAN1PREFIX}/man/$${locale}/man1/nmap.1; \
	done

.include <bsd.port.post.mk>
