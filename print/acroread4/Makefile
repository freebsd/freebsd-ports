# New ports collection makefile for:	acroread
# Date created:		16 November 1996
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	acroread
PORTVERSION=	4.05
CATEGORIES=	print linux
MASTER_SITES=	ftp://ftp.adobe.com/pub/adobe/acrobatreader/unix/4.x/
.include <bsd.port.pre.mk>
.if ${ARCH} == "i386"
DISTNAME=	linux-ar-405
.elif ${ARCH} == "alpha"
DISTNAME=	fdec-rs-405
.endif

MAINTAINER=	dima@FreeBSD.org

.if ${ARCH} == "i386"
USE_LINUX=	yes
.elif ${ARCH} == "alpha"
RUN_DEPENDS=	/compat/osf1/usr/shlib/libc.so:${PORTSDIR}/emulators/osf1_base
.endif

ONLY_FOR_ARCHS=	i386 alpha

USE_REINPLACE=	yes
LATEST_LINK=	acroread4
NO_FILTER_SHLIBS=	yes

.if ${ARCH} == "i386"
WRKSRC=		${WRKDIR}/ILINXR.install
PLIST_SUB=	"ARCHDIR=intellinux"
.elif ${ARCH} == "alpha"
WRKSRC=		${WRKDIR}/AOSFRS.install
PLIST=		${WRKDIR}/PLIST
PLIST_SUB=	"ARCHDIR=alphaosf"
.endif

pre-configure:
.if ${ARCH} == "i386"
	@${REINPLACE_CMD} -e 's:Linux):FreeBSD|Linux):g' ${WRKSRC}/INSTALL
.elif ${ARCH} == "alpha"
	@${REINPLACE_CMD} -e 's:OSF1):FreeBSD|OSF1):g' ${WRKSRC}/INSTALL
	${SED} -e 's/@comment ALPHA-ONLY://g' ${PKGDIR}/pkg-plist > ${PLIST}
.endif

do-build:
	@${ECHO_MSG} "Do a \`make install' as root."

do-install:
	@${MKDIR} ${PREFIX}/Acrobat4
	@ReadInstallDir=${PREFIX}/Acrobat4 ${WRKSRC}/INSTALL

post-install:
.if ${ARCH} == "i386"
	@${REINPLACE_CMD} -e 's:Linux):FreeBSD|Linux):g' ${PREFIX}/Acrobat4/bin/acroread
	-@/compat/linux/usr/bin/strip ${PREFIX}/Acrobat4/Reader/intellinux/bin/acroread
	@brandelf -t Linux ${PREFIX}/Acrobat4/Reader/intellinux/bin/acroread
.elif ${ARCH} == "alpha"
	@${REINPLACE_CMD} -e 's:OSF1):FreeBSD|OSF1):g' ${PREFIX}/Acrobat4/bin/acroread
	@strip ${PREFIX}/Acrobat4/Reader/alphaosf/bin/acroread
.endif
	@cd ${PREFIX}/Acrobat4/bin && \
	  ${PATCH} --quiet < ${FILESDIR}/acroread.diff && \
	  ${INSTALL_SCRIPT} ${PREFIX}/Acrobat4/bin/acroread \
	     ${PREFIX}/bin/acroread4 && ${RM} acroread.orig
	@${CHOWN} -R -h root:wheel ${PREFIX}/Acrobat4
	@${CHMOD} +x ${PREFIX}/bin/acroread4
	[ -e ${PREFIX}/bin/acroread ] \
	    || (cd ${PREFIX}/bin ; ${LN} -s acroread4 acroread)
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/Acrobat4/Reader/License.pdf"

.include <bsd.port.post.mk>
