# Ports collection makefile for:  Howto
# Date created:			  Fri Oct 02, 1998
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	Howto
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	ftp://metalab.unc.edu/pub/Linux/docs/HOWTO/other-formats/sgml/ \
		ftp://metalab.unc.edu/pub/Linux/docs/HOWTO/mini/other-formats/sgml/ \
		ftp://metalab.unc.edu/pub/Linux/docs/HOWTO/other-formats/docbook/
DISTFILES=	Linux+FreeBSD.sgml.gz  \
		DNS-HOWTO.sgml.gz  \
		NFS-HOWTO.sgml.gz  \
		NIS-HOWTO.sgml.gz  \
		Security-HOWTO.sgml.gz

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	sgmlfmt:${PORTSDIR}/textproc/sgmlformat

DIST_SUBDIR=	Howto
NO_WRKSUBDIR=	yes

do-extract:
	@${MKDIR} ${WRKSRC}
	@for file in ${DISTFILES}; do \
		${CP} ${_DISTDIR}/$$file ${WRKSRC} ; \
		case $$file in \
			*.Z|*.gz) \
				${GZIP_CMD} -d ${WRKSRC}/$$file ; \
				;; \
			*.zip) \
				cd ${WRKSRC} && unzip $$file ; \
				;; \
			*.bz2) \
				bzip2 -d ${WRKSRC}/$$file ; \
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
	@${MKDIR} ${PREFIX}/share/doc/Howto/HTML
	@${INSTALL_MAN} ${FILESDIR}/HOWTO-INDEX.html ${PREFIX}/share/doc/Howto
	@${INSTALL_MAN} ${WRKSRC}/*.html ${PREFIX}/share/doc/Howto/HTML
	@${INSTALL_MAN} ${WRKSRC}/*.latin1 ${PREFIX}/share/doc/Howto
	@${INSTALL_MAN} ${WRKSRC}/*.ascii ${PREFIX}/share/doc/Howto

.include <bsd.port.mk>
