# New ports collection makefile for:	acroread-commfont
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	acroread
PORTVERSION=	1999.7.20
PKGNAMESUFFIX=	-${DISTNAME}
CATEGORIES+=	print linux
MASTER_SITES=	ftp://ftp-pac.adobe.com/pub/adobe/acrobatreader/unix/4.x/
DISTNAME?=	commfont # dummy

MAINTAINER=	taoka@FreeBSD.org

NO_BUILD=	yes
SLAVEDIRS=	chinese/acroread-chsfont chinese/acroread-chtfont

.include <bsd.port.pre.mk>

.if ${DISTNAME} == "commfont"
###### For this port #############################
.if exists(${DISTDIR}/jpnfont.tar.gz)
DISTFILES=	jpnfont.tar.gz
WRKSRC=		${WRKDIR}/JPNKIT
.elif exists(${DISTDIR}/chsfont.tar.gz)
DISTFILES=	chsfont.tar.gz
WRKSRC=		${WRKDIR}/CHSKIT
.elif exists(${DISTDIR}/chtfont.tar.gz)
DISTFILES=	chtfont.tar.gz
WRKSRC=		${WRKDIR}/CHTKIT
.elif exists(${DISTDIR}/korfont.tar.gz)
DISTFILES=	korfont.tar.gz
WRKSRC=		${WRKDIR}/KORKIT
.else
DISTFILES=	korfont.tar.gz
WRKSRC=		${WRKDIR}/KORKIT
.endif
#NO_CHECKSUM=	yes
TAR_FILE=	${WRKSRC}/LANGCOM.TAR
RUN_DEPENDS=	acroread4:${PORTSDIR}/print/acroread4
.else
###### For slave ports ##############################
## Use a local directory of the slave port!!
COMMENT=	${.CURDIR}/pkg-comment
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
FILESDIR=	${.CURDIR}/files
##
RUN_DEPENDS=	${PREFIX}/Acrobat4/Resource/CMap/H:${PORTSDIR}/print/acroread-commfont
#
.if ${DISTNAME} == "jpnfont"
RESTRICTED=	"Be required to register with Adobe before downloading the Japanese font pack."
IS_INTERACTIVE=	"You should manual-fetch Japanese pack of \"Asian Font Packs\" from http://www.adobe.com/prodindex/acrobat/readstep.html"
.if !exists(${DISTDIR}/jpnfont.tar.gz)
IGNORE=		": ${RESTRICTED} ${IS_INTERACTIVE}"
.endif
WRKSRC=		${WRKDIR}/JPNKIT
TAR_FILE=	${WRKSRC}/LANGJPN.TAR
.elif ${DISTNAME} == "chsfont"
WRKSRC=		${WRKDIR}/CHSKIT
TAR_FILE=	${WRKSRC}/LANGCHS.TAR
.elif ${DISTNAME} == "chtfont"
WRKSRC=		${WRKDIR}/CHTKIT
TAR_FILE=	${WRKSRC}/LANGCHT.TAR
.elif ${DISTNAME} == "korfont"
WRKSRC=		${WRKDIR}/KORKIT
TAR_FILE=	${WRKSRC}/LANGKOR.TAR
.endif
.endif

do-install:
	@${MKDIR} ${PREFIX}/Acrobat4/Resource
	@${TAR} xf ${TAR_FILE} -C ${PREFIX}/Acrobat4/Resource

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
