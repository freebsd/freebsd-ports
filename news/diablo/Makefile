# New ports collection makefile for:		diablo
# Date created:					June 2nd 1997
# Whom:						jfitz
#
# $FreeBSD$
#

PORTNAME=	diablo
PORTVERSION=	1.15
CATEGORIES=	news
MASTER_SITES=	http://www.backplane.com/diablo/
DISTNAME=	${PKGNAME}-rel	
EXTRACT_SUFX=	.tgz

MAINTAINER=	jfitz@FreeBSD.org

BUILD_DEPENDS=	xmake:${PORTSDIR}/devel/xmake

WRKSRC=		${WRKDIR}/diablo

NO_PACKAGE=	"has to create/verify news user"

MAN5=		diablo-files.5 diablo-kp.5
MAN8=		diablo.8 dclean.8 dicmd.8 dexpire.8 didump.8 \
		dilookup.8 doutq.8 dspoolout.8 dkp.8 dnewslink.8 \
		dreadart.8 dreaderd.8 dsyncgroups.8


do-configure:
	${CP} ${FILESDIR}/post-install-notes ${WRKSRC}
	${SETENV} ${MAKE_ENV} /usr/bin/perl -pi -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/post-install-notes

do-build:
	cd ${WRKSRC} && ${PREFIX}/bin/xmake clean all

pre-install:
	@ ${SETENV} ${MAKE_ENV} ${PERL} ${SCRIPTDIR}/createuser
	${MKDIR} ${PREFIX}/news ${PREFIX}/news/dbin ${PREFIX}/news/spool \
		${PREFIX}/news/spool/news ${PREFIX}/share/doc/diablo
	${RM} -f /news
	${LN} -sf ${PREFIX}/news /news
	${CHOWN} -R news.news ${PREFIX}/news

do-install:
	cd ${WRKSRC} && ${PREFIX}/bin/xmake install
.for file in COPYRIGHT INSTALL README.READER README.SERVER RELEASE_NOTES
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/diablo
.endfor
	${INSTALL_DATA} ${WRKSRC}/post-install-notes ${PREFIX}/share/doc/diablo

post-install:
	${INSTALL} -c -o news -g news ${WRKSRC}/samples/* ${PREFIX}/news
	@ ${ECHO} "Installing ${PREFIX}/etc/rc.d/diablo.sh startup script"
	@ ${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/diablo.sh
	@ ${ECHO} "#" >> ${PREFIX}/etc/rc.d/diablo.sh
	@ ${ECHO} "" >> ${PREFIX}/etc/rc.d/diablo.sh
	@ ${ECHO} "# The line to run diablo is specifically commented out" >> \
		${PREFIX}/etc/rc.d/diablo.sh
	@ ${ECHO} "# so that you don't start up diablo with a generic config" >> \
		${PREFIX}/etc/rc.d/diablo.sh
	@ ${ECHO} "# Once you've configured diablo, uncomment the line below" >> \
		${PREFIX}/etc/rc.d/diablo.sh
	@ ${ECHO} "" >> ${PREFIX}/etc/rc.d/diablo.sh
	@ ${ECHO} "if [ -x ${PREFIX}/news/rc.news ]" >> \
		${PREFIX}/etc/rc.d/diablo.sh
	@ ${ECHO} "then" >> ${PREFIX}/etc/rc.d/diablo.sh
	@ ${ECHO} "#	${PREFIX}/news/rc.news && ${ECHO} -n ' diablo'" >> \
		${PREFIX}/etc/rc.d/diablo.sh
	@ ${ECHO} "	${ECHO} -n ' diablo(disabled)'" >> \
		${PREFIX}/etc/rc.d/diablo.sh
	@ ${ECHO} "fi" >> ${PREFIX}/etc/rc.d/diablo.sh
	${CHMOD} 0750 ${PREFIX}/etc/rc.d/diablo.sh
.if !defined(BATCH)
	@ /usr/bin/more -e ${PREFIX}/share/doc/diablo/post-install-notes
.endif

.include <bsd.port.mk>
