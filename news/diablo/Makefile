# New ports collection makefile for:		diablo
# Date created:					June 2nd 1997
# Whom:						jfitz
#
# $FreeBSD$
#

PORTNAME=	diablo
PORTVERSION=	3.0
CATEGORIES=	news
MASTER_SITES=	http://www.openusenet.org/diablo/download/
DISTNAME=	${PKGNAME}-REL
EXTRACT_SUFX=	.tgz

MAINTAINER=	des@FreeBSD.org

BUILD_DEPENDS=	xmake:${PORTSDIR}/devel/xmake

MAN5=		diablo-kp.5 diablo-files.5
MAN8=		dicmd.8 didump.8 dexpireover.8 dfeedinfo.8 dgrpctl.8 \
		dilookup.8 diloadfromspool.8 doutq.8 dreadart.8 \
		dreaderd.8 dpath.8 drcmd.8 dsyncgroups.8 dreadover.8 \
		dkp.8 diablo.8 dexpire.8 dspoolout.8 dnewslink.8

DOCDIR=		${PREFIX}/share/doc/diablo

post-extract:
	${CP} ${SCRIPTDIR}/diablo.sh ${WRKDIR}

do-configure:
	${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKDIR}/diablo.sh ${WRKSRC}/XMakefile.inc
.ifndef WITH_DES
	${PERL} -pi -e 's| -ldes||g' ${WRKSRC}/XMakefile.inc
.endif

do-build:
	cd ${WRKSRC} && xmake all

pre-install:
	${INSTALL} -d ${DOCDIR} ${PREFIX}/news ${PREFIX}/news/dbin

do-install:
	cd ${WRKSRC} && xmake install
.for file in COPYRIGHT INSTALL README.READER README.SERVER RELEASE_NOTES
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCDIR}
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/diablo.sh ${PREFIX}/etc/rc.d

post-install:
	@${CAT} ${PKGMESSAGE}
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${RM} -rf ${PREFIX}/news/man

.include <bsd.port.mk>
