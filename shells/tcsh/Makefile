# New ports collection makefile for:	tcsh
# Date created:		22 August 1994
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	tcsh
PORTVERSION=	6.09.01
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_TCSH}
DISTNAME=	${DISTNAME_TCSH}

MAINTAINER=	ports@FreeBSD.org

Y2K=		ftp://ftp.astron.com/pub/tcsh/Y2K

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 400021
NO_BUILD=	yes
PLIST=		${PKGDIR}/PLIST.nobuild
DISTFILES=	# empty

do-patch:
.else
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}
ALL_TARGET=	all catalogs
INSTALL_TARGET=	install install.man
MAN1=		tcsh.1
MASTER_SITE_TCSH=	http://www2.wbs.ne.jp/~znc/tcsh/
DISTNAME_TCSH=	${PORTNAME}-${PORTVERSION}
.endif

.if ${OSVERSION} >= 400021
pre-fetch:
	@${ECHO_MSG} "This port is just for making symlink from /bin/tcsh"
	@${ECHO_MSG} "to ${PREFIX}/bin/tcsh and updating /etc/shells."

do-install:
	${LN} -sf /bin/tcsh ${PREFIX}/bin/tcsh
.else
post-install:
	${CHOWN} bin.bin ${PREFIX}/bin/tcsh
	${CHOWN} bin.bin ${PREFIX}/man/man1/tcsh.1
	${INSTALL_DATA} ${WRKSRC}/tcsh.C.cat ${PREFIX}/share/nls/C/tcsh.cat
	${INSTALL_DATA} ${WRKSRC}/tcsh.german.cat ${PREFIX}/share/nls/de_DE.ISO_8859-1/tcsh.cat
	${LN} -sf ${PREFIX}/share/nls/de_DE.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/de_AT.ISO_8859-1/tcsh.cat
	${LN} -sf ${PREFIX}/share/nls/de_DE.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/de_CH.ISO_8859-1/tcsh.cat
	@${MKDIR} ${PREFIX}/share/nls/el_GR.ISO_8859-7
	${INSTALL_DATA} ${WRKSRC}/tcsh.greek.cat ${PREFIX}/share/nls/el_GR.ISO_8859-7/tcsh.cat
	${INSTALL_DATA} ${WRKSRC}/tcsh.spanish.cat ${PREFIX}/share/nls/es_ES.ISO_8859-1/tcsh.cat
	${INSTALL_DATA} ${WRKSRC}/tcsh.finnish.cat ${PREFIX}/share/nls/fi_FI.ISO_8859-1/tcsh.cat
	${INSTALL_DATA} ${WRKSRC}/tcsh.french.cat ${PREFIX}/share/nls/fr_FR.ISO_8859-1/tcsh.cat
	${LN} -sf ${PREFIX}/share/nls/fr_FR.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/fr_BE.ISO_8859-1/tcsh.cat
	${LN} -sf ${PREFIX}/share/nls/fr_FR.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/fr_CA.ISO_8859-1/tcsh.cat
	${LN} -sf ${PREFIX}/share/nls/fr_FR.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/fr_CH.ISO_8859-1/tcsh.cat
	${INSTALL_DATA} ${WRKSRC}/tcsh.italian.cat ${PREFIX}/share/nls/it_IT.ISO_8859-1/tcsh.cat
.endif
	@${ECHO} "Updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/tcsh /etc/shells.bak; \
	  ${ECHO} ${PREFIX}/bin/tcsh) > /etc/shells
	@${RM} /etc/shells.bak

.include <bsd.port.post.mk>
