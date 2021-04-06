# Created by: Matthew Luckie <mjl@luckie.org.nz>

PORTNAME=	thunderbird-dictionaries
PORTVERSION=	20060220
PORTREVISION=	13
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

# All available dictionaries are listed in Makefile.dict
# Makefile.dict pulls in Makefile.options
.include "${.CURDIR}/Makefile.dict"

.include <bsd.port.options.mk>

# this dictionary requires special handling in do-install
BG_DICT=	BG

# Figure out which distfiles to use, and how to construct the plist
.for f in ${ALLDICTS}
.if ${PORT_OPTIONS:M${f}}
DISTFILES+=	${${f}_FILE}
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

.include <bsd.port.mk>
