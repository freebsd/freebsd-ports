# New ports collection makefile for:	acroread
# Date created:		16 November 1996
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	acroread
PORTVERSION=	5.08
CATEGORIES=	print linux
MASTER_SITES=	http://download.adobe.com/pub/adobe/acrobatreader/unix/5.x/ \
		ftp://ftp.adobe.com/pub/adobe/acrobatreader/unix/5.x/
.include <bsd.port.pre.mk>
.if ${ARCH} == "i386"
DISTNAME=	linux-508
.endif
CONFLICTS=	acroread-3*
DIST_SUBDIR=	acroread

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	View, distribute and print PDF documents

FORBIDDEN=	arbitrary command execution http://vuxml.freebsd.org/78348ea2-ec91-11d8-b913-000c41e2cdad.html

ONLY_FOR_ARCHS=	i386

USE_LINUX=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i '' -E
NO_FILTER_SHLIBS=	yes

.if ${ARCH} == "i386"
PLIST_SUB=	"ARCHDIR=intellinux"
.endif
WRKSRC=		${WRKDIR}

do-build:
	@${ECHO_MSG} "Do a \`make install' as root."

do-install:
	@${MKDIR} ${PREFIX}/Acrobat5
	@ReadInstallDir=${PREFIX}/Acrobat5 ${WRKDIR}/INSTALL
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	strings -1 ${WRKDIR}/README > ${DOCSDIR}/README
.endif

post-install:
	${REINPLACE_CMD} 's:Linux):FreeBSD|Linux):g' ${PREFIX}/Acrobat5/bin/acroread
	-@${LINUXBASE}/usr/bin/strip ${PREFIX}/Acrobat5/Reader/intellinux/bin/acroread
	@brandelf -t Linux ${PREFIX}/Acrobat5/Reader/intellinux/bin/acroread
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
