# New ports collection makefile for:	leafnode+
# Version required:	2.10
# Date created:		19 November 1998
# Whom:			Tom Hukins <tom@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	leafnode+-2.10
CATEGORIES=	news
MASTER_SITES=	ftp://hiroshima.isdn.uiuc.edu/leafnode+/

MAINTAINER=	tom@FreeBSD.org

MAN8=		checkgroups.8 fetchnews.8 leafnode.8 texpire.8
PKGINSTALL=	${WRKDIR}/INSTALL

.if defined(NOPORTDOCS)
PLIST=	${PKGDIR}/PLIST.nodocs
.endif

LEAFLIBDIR?=	${PREFIX}/lib/leafnode
LEAFSPOOLDIR?=	/var/spool/leafnode
REWRITE=	${SED} -e "s:@LIBDIR@:${LEAFLIBDIR}:g" \
		-e "s:@SPOOLDIR@:${LEAFSPOOLDIR}:g" \
		-e "s:@PREFIX@:${PREFIX}:g"

post-patch:
.for file in Makefile FAQ INSTALL README leafnode.8
	@${MV} ${WRKSRC}/${file} ${WRKSRC}/${file}.bak
	@${REWRITE} ${WRKSRC}/${file}.bak > ${WRKSRC}/${file}
.endfor
	@${REWRITE} ${FILESDIR}/INSTALL.in > ${PKGINSTALL}
	@${CHMOD} 755 ${PKGINSTALL}

do-install:
.for file in leafnode fetchnews texpire checkgroups leaftool
	@${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/sbin
.endfor
.for file in ${MAN8}
	@${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/man/man8
.endfor
.if !defined{NOPORTDOCS}
	@${ECHO} "===>  Copying documents to ${PREFIX}/share/doc/leafnode+"
	@${MKDIR} ${PREFIX}/share/doc/leafnode+
.for file in Changes FAQ INSTALL README config.example
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/leafnode+
.endfor
.endif
.if !exists{LEAFSPOOLDIR} || !exists{{LEAFLIBDIR}
	@${MKDIR} ${LEAFSPOOLDIR} ${LEAFLIBDIR}
	@${MKDIR} ${LEAFSPOOLDIR}/interesting.groups
	@${MKDIR} ${LEAFSPOOLDIR}/out.going
.for dir_a in 0 1 2 3 4 5 6 7 8 9
.for dir_b in 0 1 2 3 4 5 6 7 8 9
.for dir_c in 0 1 2 3 4 5 6 7 8 9
	@${MKDIR} ${LEAFSPOOLDIR}/message.id/${dir_a}${dir_b}${dir_c}
.endfor
.endfor
.endfor
	@${CHOWN} -R news:news ${LEAFSPOOLDIR} ${LEAFLIBDIR}
	@${CHMOD} 2750 ${LEAFSPOOLDIR}
.endif

.include <bsd.port.mk>
