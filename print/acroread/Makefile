# New ports collection makefile for:	acroread
# Date created:		16 November 1996
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	acroread
PORTVERSION=	5.10
PORTREVISION=	1
CATEGORIES=	print linux
MASTER_SITES=	http://download.adobe.com/pub/adobe/acrobatreader/unix/5.x/ \
		ftp://ftp.adobe.com/pub/adobe/acrobatreader/unix/5.x/
.include <bsd.port.pre.mk>
DISTNAME=	linux-5010
DIST_SUBDIR=	acroread

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	View, distribute and print PDF documents

RUN_DEPENDS=	${LINUXBASE}/usr/X11R6/lib/libX11.so.6:${PORTSDIR}/x11/linux-XFree86-libs

ONLY_FOR_ARCHS=	amd64 i386
USE_REINPLACE=	yes
NO_BUILD=	yes
REINPLACE_ARGS=	-i '' -E
NO_FILTER_SHLIBS=	yes

PLIST_SUB=	"ARCHDIR=intellinux"
WRKSRC=		${WRKDIR}/installers

do-install:
	@${MKDIR} ${PREFIX}/Acrobat5
	@ReadInstallDir=${PREFIX}/Acrobat5 ${WRKSRC}/INSTALL
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	strings -1 ${WRKSRC}/README > ${DOCSDIR}/README
.endif

post-install:
	${REINPLACE_CMD} 's:Linux):FreeBSD|Linux):g' ${PREFIX}/Acrobat5/bin/acroread
	@${BRANDELF} -t Linux ${PREFIX}/Acrobat5/Reader/intellinux/bin/acroread
	${REINPLACE_CMD} 's:OSF1):FreeBSD|OSF1):g' ${PREFIX}/Acrobat5/bin/acroread
	@cd ${PREFIX}/Acrobat5/bin && \
	  ${INSTALL_SCRIPT} ${PREFIX}/Acrobat5/bin/acroread \
	     ${PREFIX}/bin/acroread5
	@${CHOWN} -R -h root:wheel ${PREFIX}/Acrobat5
	@${CHMOD} +x ${PREFIX}/bin/acroread5
	[ -e ${PREFIX}/bin/acroread ] \
	    || (cd ${PREFIX}/bin ; ${LN} -sf acroread5 acroread)
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/Acrobat5/Reader/license.txt"

.include <bsd.port.post.mk>
