# New ports collection makefile for:	exslt
# Date created:				2004-07-08
# Whom:					Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
#
# $FreeBSD$
#

PORTNAME=	exslt
PORTVERSION=	2003.10.24
CATEGORIES=	textproc
MASTER_SITES=	http://www.exslt.org/
DISTNAME=	all-${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Community initiative extensions to XSLT

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

DATAFILES=	base.css date dyn exsl func howto.html index.html math random regexp set str

do-install:
	@${ECHO_MSG} ">> Installing stylesheets and documentation in ${DATADIR}"
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC} && \
		${FIND} ${DATAFILES} -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
		${FIND} ${DATAFILES} ! -type d -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;

post-install:
	@${FIND} -s ${DATAFILES:S/^/${DATADIR}\//} ! -type d 2>/dev/null | \
		${SED} -ne 's,^${PREFIX}/,,p' >> ${TMPPLIST}
	@${FIND} -s -d ${DATAFILES:S/^/${DATADIR}\//} -type d 2>/dev/null | \
		${SED} -ne 's,^${PREFIX}/,@dirrm ,p' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${DATADIR:S,^${PREFIX}/,,}' >> ${TMPPLIST}

.include <bsd.port.mk>
