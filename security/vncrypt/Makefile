# New ports collection makefile for:	vncrypt
# Date created:			22 Jan 2002
# Whom:				Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vncrypt
PORTVERSION=	1.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Cryptographic disk driver for FreeBSD

NO_PACKAGE=	"Depends on kernel"
PLIST_SUB=	KMODDIR=${KMODDIR} DOCSDIR="share/doc/${PORTNAME}"
MAKE_ENV+=	BINDIR=${PREFIX}/sbin
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

SUP_OS_VER=	450004
.if ${OSVERSION} < ${SUP_OS_VER}
BROKEN=		"OS versions prior to ${SUP_OS_VER} is not supported"
.endif

.if ${OSVERSION} >= 502112
BROKEN=		"Does not compile on FreeBSD >= 5.x"
.endif

.ifdef(IPSEC)
#Compile for kernel with IPSEC support
MAKE_ENV+=	CRYPTO_SRCS=""
.endif

DOCS_LANG=	en ru
DOCS_en=	README
DOCS_ru=	README.rus doc/*rus*

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
.for _LANG in ${DOCS_LANG}
	@${MKDIR} ${DOCSDIR}/${_LANG}
.for DOCFILE in ${DOCS_${_LANG}}
	@${INSTALL_DATA} ${WRKSRC}/${DOCFILE} ${DOCSDIR}/${_LANG}
.endfor
.endfor
.endif
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" ${.CURDIR}/pkg-message >${PKGMESSAGE}
.ifndef(BATCH)
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
.endif

.include <bsd.port.post.mk>
