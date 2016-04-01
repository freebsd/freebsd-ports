# Created by: Matthew Luckie <mjl@luckie.org.nz>
# $FreeBSD$

PORTNAME=	thunderbird-dictionaries
PORTVERSION=	20060220
PORTREVISION=	11
CATEGORIES=	mail
MASTER_SITES=	MOZDEV/dictionaries
DISTFILES=	# filled in later after options
DIST_SUBDIR=	thunderbird

MAINTAINER=	mjl@luckie.org.nz
COMMENT=	Dictionaries for Mozilla Thunderbird

RUN_DEPENDS=	thunderbird>=6.0:mail/thunderbird

USES=		zip:infozip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/dictionaries

.include "${.CURDIR}/Makefile.options"

.include <bsd.port.pre.mk>

.include "${.CURDIR}/Makefile.dict"

# For batch building, build all dictionaries
.if defined(BATCH)
PORT_OPTIONS+=	${ALLDICTS}
.endif

# All available dictionaries are listed in Makefile.dict

# this dictionary requires special handling in do-install
BG_DICT=	BG

# Build and install all dictionaries
.if ${PORT_OPTIONS:MALL}
PORT_OPTIONS+=	${ALLDICTS}
.endif

# Figure out which distfiles to use, and how to construct the plist
.for f in ${ALLDICTS}
.if ${PORT_OPTIONS:M${f}}
PLIST_SUB+=	${f}=""
HAVE_DICT=	yes
DISTFILES+=	${${f}_FILE}
.else
PLIST_SUB+=	${f}="@comment "
.endif
.endfor

# Extract the relevant distfiles
do-extract:
	@${MKDIR} ${WRKSRC}
.for f in ${ALLDICTS}
.if  ${PORT_OPTIONS:M${f}}
	@${UNZIP_CMD} -q ${DISTDIR}/${DIST_SUBDIR}/${${f}_FILE} -d ${WRKSRC}/${${f}_FILE}
.endif
.endfor

# Install the requested dictionaries
do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/thunderbird/dictionaries
.for f in ${ALLDICTS}
.if ${PORT_OPTIONS:M${f}}
.if ${BG_DICT}==${f}
	${INSTALL_DATA} \
		${WRKSRC}/${${f}_FILE}/bin/components/myspell/${${f}_FILE:S/spell-//:S/xpi//}aff \
		${STAGEDIR}${PREFIX}/lib/thunderbird/dictionaries
	${INSTALL_DATA} \
		${WRKSRC}/${${f}_FILE}/bin/components/myspell/${${f}_FILE:S/spell-//:S/xpi//}dic \
		${STAGEDIR}${PREFIX}/lib/thunderbird/dictionaries
.else
	${INSTALL_DATA} \
		${WRKSRC}/${${f}_FILE}/${${f}_FILE:S/spell-//:S/xpi//}aff \
		${STAGEDIR}${PREFIX}/lib/thunderbird/dictionaries
	${INSTALL_DATA} \
		${WRKSRC}/${${f}_FILE}/${${f}_FILE:S/spell-//:S/xpi//}dic \
		${STAGEDIR}${PREFIX}/lib/thunderbird/dictionaries
.endif
.endif
.endfor

.include <bsd.port.post.mk>
