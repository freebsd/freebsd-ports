# New ports collection makefile for:		Ports tree snapshot utility
# Date created:					29 October 2004
# Whom:						cperciva@daemonology.net
#
# $FreeBSD$
#

PORTNAME=	portsnap
PORTVERSION=	1.1
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.daemonology.net/portsnap/

MAINTAINER=	cperciva@daemonology.net
COMMENT=	Provides secure snapshots of the ports directory

RUN_DEPENDS=	bspatch:${PORTSDIR}/misc/bsdiff

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600021 && ( ${OSVERSION} < 504102 || ${OSVERSION} > 599999 )
RUN_DEPENDS+=	sha256:${PORTSDIR}/sysutils/freebsd-sha256
.endif

.if ${OSVERSION} > 600033 || ( ${OSVERSION} > 504103 && ${OSVERSION} < 600000 )
IGNORE=		portsnap now contained in the base system
.endif

MAN5=		portsnap.conf.5
MAN8=		portsnap.8
PLIST_FILES=	etc/portsnap.conf.sample sbin/portsnap		\
		libexec/phttpget				\
		libexec/make_index portsnap/.package.this.directory
PLIST_DIRS=	portsnap
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

post-patch:
	${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" \
		${WRKSRC}/portsnap ${WRKSRC}/portsnap.8

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/portsnap ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/make_index ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/phttpget ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/portsnap.conf.5 ${PREFIX}/man/man5/
	${INSTALL_MAN} ${WRKSRC}/portsnap.8 ${PREFIX}/man/man8/
	${INSTALL_DATA} ${WRKSRC}/portsnap.conf		\
		${PREFIX}/etc/portsnap.conf.sample
	${MKDIR} ${PREFIX}/portsnap
	${TOUCH} ${PREFIX}/portsnap/.package.this.directory

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
