# New ports collection makefile for:    Adobe Acrobar Viewer Version 1.1
# Date created:				4 Febrary 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	acrobatviewer
PORTVERSION=	1.1
CATEGORIES=	print java
MASTER_SITES=	ftp://ftp.adobe.com/pub/adobe/magic/acrobatviewer/unix/1.x/
DISTNAME=	viewer.bin
EXTRACT_SUFX=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Viewer for the PDF files written in Java(TM)

RUN_DEPENDS=	${JAVAVM}:${PORTSDIR}/java/javavmwrapper \
		${LOCALBASE}/etc/javavms:${PORTSDIR}/java/jre

USE_ZIP=	yes
USE_XLIB=	yes
USE_PERL5_BUILD=yes
NO_BUILD=	yes

JAVAVM=		${LOCALBASE}/bin/javavm

INSTSBDR=	${PREFIX}/share/java/AdobeAcrobatViewer

# For the end-users this "InstallAnywhere" whizard probably is a great step
# toward Windowze-like software installations comparing with traditional
# "make install" enviropment, but for *nix administrator it is a pain to deal
# with. Fortunately, Zero G (author of the InstallAnywhere) does not use
# propiertary format for archiving files, so it was possible for me to make
# following dirty hack. If they will provide better way to centralise
# installations in the next versions of InstallAnywhere than I'll be glad to
# remove all following crap.

BLOCKSIZE=	32768
ARCHSTART=	1
ARCHSIZE=	2749762
ARCHBLOCKS=	84

do-extract:
		@${MKDIR} ${WRKSRC} && \
		cd ${WRKSRC} && \
		dd if=${DISTDIR}/${DISTNAME} of=archive.zip bs=${BLOCKSIZE} skip=${ARCHSTART} count=${ARCHBLOCKS} 2>/dev/null && \
		${LOCALBASE}/bin/unzip -o -a -j -qq archive.zip && \
		${PERL} -pi -e "s.\x0D.." ${WRKSRC}/AcrobatViewer.lax

do-configure:
		@${PERL} -pi -e "s|%INSTDIR%|${INSTSBDR}|g" ${WRKSRC}/AcrobatViewer.lax && \
		${PERL} -pi -e "s|%JAVAVM%|${JAVAVM}|g" ${WRKSRC}/AcrobatViewer.lax && \
		${PERL} -pi -e "s|%JAVAJIT%|${JAVAJIT}|g" ${WRKSRC}/AcrobatViewer.lax

do-install:
		${MKDIR} ${INSTSBDR}
		${INSTALL_SCRIPT} ${WRKSRC}/launixgc.sh ${INSTSBDR}/AcrobatViewer
		${INSTALL_DATA} ${WRKSRC}/License.pdf ${INSTSBDR}/
		${INSTALL_DATA} ${WRKSRC}/help.pdf ${INSTSBDR}/
		${INSTALL_DATA} ${WRKSRC}/lax.jar ${INSTSBDR}/
		${INSTALL_DATA} ${WRKSRC}/acrobat.jar ${INSTSBDR}/
		${INSTALL_DATA} ${WRKSRC}/AcrobatViewer.lax ${INSTSBDR}/
		${LN} -sf ${INSTSBDR}/AcrobatViewer ${PREFIX}/bin/AcrobatViewer

post-install:
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
