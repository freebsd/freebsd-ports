# New ports collection makefile for:	acroread
# Date created:		16 November 1996
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	acroread
PORTVERSION=	3.02
CATEGORIES=	print linux
MASTER_SITES=	ftp://ftp.adobe.com/pub/adobe/acrobatreader/unix/3.x/ \
		ftp://sunsite.cnlab-switch.ch/mirror/FreeBSD/ports/distfiles/
.include <bsd.port.pre.mk>
.if ${ARCH} == "i386"
DISTNAME=	ar302lin
.elif ${ARCH} == "alpha"
DISTNAME=	ar302osf
.endif
EXTRACT_SUFX=	.tar.Z
LATEST_LINK=	acroread3

FORBIDDEN=	http://vuxml.freebsd.org/78348ea2-ec91-11d8-b913-000c41e2cdad.html security
DEPRECATED=	${FORBIDDEN}
EXPIRATION_DATE=2004-11-21

MAINTAINER=	ports@FreeBSD.org
COMMENT=	View, distribute and print PDF documents

.if ${ARCH} == "i386"
RUN_DEPENDS=${LINUXBASE}/lib/ld-linux.so.1:${PORTSDIR}/emulators/linux_base-6
.elif ${ARCH} == "alpha"
RUN_DEPENDS=	/compat/osf1/usr/shlib/libc.so:${PORTSDIR}/emulators/osf1_base
.endif

CONFLICTS=	acroread-5*
ONLY_FOR_ARCHS=	i386 alpha

NO_FILTER_SHLIBS=	yes
USE_REINPLACE=	yes

.if ${ARCH} == "i386"
WRKSRC=		${WRKDIR}/ILINXR.install
PLIST_SUB=	"ARCHDIR=intellinux"
.elif ${ARCH} == "alpha"
WRKSRC=		${WRKDIR}/AOSFR.install
PLIST_SUB=	"ARCHDIR=alphaosf"
.endif

pre-configure:
.if ${ARCH} == "i386"
	@${REINPLACE_CMD} -e 's:Linux):FreeBSD|Linux):g' ${WRKSRC}/INSTALL
.elif ${ARCH} == "alpha"
	@${REINPLACE_CMD} -e 's:OSF1):FreeBSD|OSF1):g' ${WRKSRC}/INSTALL
.endif

do-build:
	@${ECHO_MSG} "Do a \`make install' as root."

do-install:
	@${MKDIR} ${PREFIX}/Acrobat3
	@ReadInstallDir=${PREFIX}/Acrobat3 ${WRKSRC}/INSTALL

post-install:
.if ${ARCH} == "i386"
	@${REINPLACE_CMD} -e 's:Linux):FreeBSD|Linux):g' ${PREFIX}/Acrobat3/bin/acroread
	@${BRANDELF} -t Linux ${PREFIX}/Acrobat3/Reader/intellinux/bin/acroread
.elif ${ARCH} == "alpha"
	@${REINPLACE_CMD} -e 's:OSF1):FreeBSD|OSF1):g' ${PREFIX}/Acrobat3/bin/acroread
.endif
	@cd ${PREFIX}/Acrobat3/bin && \
	  ${PATCH} --quiet < ${FILESDIR}/acroread.diff && \
	  ${INSTALL_SCRIPT} ${PREFIX}/Acrobat3/bin/acroread \
	    ${PREFIX}/bin/acroread3 && \
	  ${RM} acroread.orig acroread.bak
	@${CHMOD} +x ${PREFIX}/bin/acroread3
	[ -e ${PREFIX}/bin/acroread ] \
	    || (cd ${PREFIX}/bin ; ${LN} -s acroread3 acroread)
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/Acrobat3/Reader/License.pdf"

.include <bsd.port.post.mk>
