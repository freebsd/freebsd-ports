# New ports collection makefile for:	highlight
# Date created:				05 August 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	highlight
PORTVERSION=	2.2.1
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.andre-simon.de/zip/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Customizable syntax highlighter

BROKEN=		Unfetchable

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

USE_GCC=	3.3
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile
MAKE_ARGS=	CC="${CXX}" \
		CFLAGS="${CXXFLAGS} ${CPPFLAGS} -DHAVE_DECL_GETOPT" \
		LDFLAGS="${LDFLAGS}"
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/highlight

MAN1=		${PORTNAME}.1
MANCOMPRESSED=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/share/highlight|${DATADIR}|' ${WRKSRC}/datadir.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../man/${MAN1}.gz ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/../langDefs/extensions.conf ${DATADIR}
	@${MKDIR} ${DATADIR}/helpmsg
	${INSTALL_DATA} ${WRKSRC}/../helpmsg/* ${DATADIR}/helpmsg
	@${MKDIR} ${DATADIR}/langDefs
	${INSTALL_DATA} ${WRKSRC}/../langDefs/*.lang ${DATADIR}/langDefs
	@${MKDIR} ${DATADIR}/themes
	${INSTALL_DATA} ${WRKSRC}/../themes/* ${DATADIR}/themes
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in AUTHORS ChangeLog INSTALL README
	${INSTALL_DATA} ${WRKSRC}/../${i} ${DOCSDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
	${TAR} -C ${WRKSRC}/../utils -cf - . | \
		${TAR} -C  ${EXAMPLESDIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

post-install:
.for dir in ${PREFIX}/share/${PORTNAME} ${PREFIX}/share/examples/${PORTNAME}
	@${FIND} ${dir} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${dir} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endfor

.include <bsd.port.post.mk>
