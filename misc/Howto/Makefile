# Ports collection makefile for:  Howto
# Date created:			  Fri Oct 02, 1998
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	Howto
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	misc
MASTER_SITES=	ftp://metalab.unc.edu/pub/Linux/docs/HOWTO/other-formats/sgml/ \
		ftp://metalab.unc.edu/pub/Linux/docs/HOWTO/other-formats/docbook/
DISTFILES=	Linux+FreeBSD.sgml.gz  \
		DNS-HOWTO.sgml.gz  \
		NFS-HOWTO.sgml.gz  \
		NIS-HOWTO.sgml.gz  \
		Security-HOWTO.sgml.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Linux HOW-TOs modified for applicablity on FreeBSD

BUILD_DEPENDS=	sgmlfmt:${PORTSDIR}/textproc/sgmlformat

BROKEN=		Size mismatch
EXPIRATION_DATE=2005-02-18
DEPRECATED=	${BROKEN}

DIST_SUBDIR=	Howto
NO_WRKSUBDIR=	yes
USE_ZIP=		yes
USE_BZIP2=		yes

do-extract:
	@${MKDIR} ${WRKSRC}
	@for f in ${DISTFILES}; do \
		${CP} ${_DISTDIR}/$$f ${WRKSRC} ; \
		case $$f in \
			*.Z|*.gz) \
				${GZIP_CMD} -d ${WRKSRC}/$$f ; \
				;; \
			*.zip) \
				cd ${WRKSRC} && ${UNZIP_CMD} $$f ; \
				;; \
			*.bz2) \
				${BZIP2_CMD} -d ${WRKSRC}/$$f ; \
				;; \
		esac; \
	done

do-build:
.for howto in ${DISTFILES:S/.gz//}
	@cd ${WRKSRC} && sgmlfmt -f ascii ${howto}
	@cd ${WRKSRC} && sgmlfmt -f latin1 ${howto}
	@cd ${WRKSRC} && sgmlfmt -f html ${howto}
.endfor

do-install:
	@${MKDIR} ${DOCSDIR}/HTML
	@${INSTALL_MAN} ${FILESDIR}/HOWTO-INDEX.html ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/*.html ${DOCSDIR}/HTML
	@${INSTALL_MAN} ${WRKSRC}/*.latin1 ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/*.ascii ${DOCSDIR}

.include <bsd.port.mk>
