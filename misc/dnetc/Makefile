# New ports collection makefile for:    dnetc
# Date created:         26 Dec 1999
# Whom:                 dbaker
#
# $FreeBSD$
#

PORTNAME=	dnetc
PORTVERSION=	2.9007.489
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.distributed.net/pub/dcti/%SUBDIR%/ \
		http://http.distributed.net/pub/dcti/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION:S/^/v/:R}
DISTFILES=	dnetc${PORTVERSION:E}-freebsd-x86-elf.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Distributed.net distributed computing project client

IGNORE=		uses an unregistered uid/gid.

WRKSRC=		${WRKDIR}/dnetc${PORTVERSION:E}-freebsd-x86-elf

ONLY_FOR_ARCHS=	i386

NO_BUILD=	yes

BINDIR=		${PREFIX}/distributed.net
LIBDIR=		${PREFIX}/etc/rc.d

CLIENTUSER=	dnetc
CLIENTGROUP=	${CLIENTUSER}

SBINMODE=	700
BINMODE=	700

MAN1=		dnetc.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
IGNORE=		"This port requires FreeBSD 3.X or greater."
.endif

.if exists(${PREFIX}/distributed.net/rc5des)
BROKEN=		"rc5des/dnetc conflict: Please deinstall all rc5des ports/packages first."
.endif

do-configure:
	@if [ ! -f ${PREFIX}/dnetc.ini ]; then \
		${INSTALL} -c -m 644 ${FILESDIR}/dnetc.ini ${WRKSRC}; \
	fi

pre-install:
	@${ECHO} "==>  Creating custom user to run dnetc..."
	${PKGINSTALL} ${PKGNAME} PRE-INSTALL "${CLIENTUSER}" "${CLIENTGROUP}"

do-install:
	@if [ ! -d ${BINDIR} ]; then \
		${MKDIR} ${BINDIR}; \
	fi

	${INSTALL} -c -m ${SBINMODE} -o ${CLIENTUSER} -g ${CLIENTGROUP} ${WRKSRC}/dnetc ${BINDIR}

	${SED} s#CHANGETHIS#${BINDIR}# < ${FILESDIR}/dnetc.sh > ${WRKSRC}/dnetc.sh.pathnames
	${INSTALL} -c -m ${SBINMODE} ${WRKSRC}/dnetc.sh.pathnames ${LIBDIR}/dnetc.sh

	${INSTALL_DATA} ${FILESDIR}/INFO ${BINDIR}

	${CHOWN} ${CLIENTUSER}:${CLIENTGROUP} ${BINDIR}
	${CHMOD} 775 ${BINDIR}

	if [ ! -f ${BINDIR}/dnetc.sh ]; then \
		${LN} -s ${LIBDIR}/dnetc.sh ${BINDIR}/dnetc.sh; \
	fi

	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1
	${INSTALL} -c -m 644 -o ${CLIENTUSER} -g ${CLIENTGROUP} ${WRKSRC}/dnetc.ini ${BINDIR}/dnetc.ini.default
.if !exists(${BINDIR}/dnetc.ini)
	@${ECHO} ""
	@${ECHO} ""
	@${ECHO} ""
	@${ECHO} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO} "! REMEMBER REMEMBER REMEMBER REMEMBER REMEMBER REMEMBER REMEMBER REMEMBER !"
	@${ECHO} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO} "           Don't forget to run '${BINDIR}/dnetc -config'                  "
	@${ECHO} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO} ""
	@${ECHO} ""
	@${ECHO} ""
	${INSTALL} -c -m 644 -o ${CLIENTUSER} -g ${CLIENTGROUP} ${WRKSRC}/dnetc.ini ${BINDIR}
.endif

.include <bsd.port.post.mk>
