# New ports collection makefile for:    dnetc
# Date created:         26 Dec 1999
# Whom:                 dbaker
#
# $FreeBSD$
#

PORTNAME=	dnetc
PORTVERSION=	2.9001.478
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.distributed.net/pub/dcti/%SUBDIR%/ \
		http://http.distributed.net/pub/dcti/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION:S/^/v/:R}
.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
DISTFILES=	dnetc${PORTVERSION:E}-freebsd-x86-elf.tar.gz
.elif ${ARCH} == "alpha"
BROKEN=		"Not immediately available.  Please try again tomorrow."
.endif

ONLY_FOR_ARCHS=	i386

.if ${OSVERSION} < 300000
BROKEN=		"No version is currently available for your system.  Please upgrade FreeBSD."
.endif

.if exists(${PREFIX}/distributed.net/rc5des)
BROKEN=		"rc5des/dnetc conflict: Please deinstall all rc5des ports/packages first."
.endif

MAINTAINER=	dbaker@FreeBSD.org

WRKSRC=		${WRKDIR}/dnetc-freebsd-x86-elf
NO_BUILD=	yes

BINDIR=		${PREFIX}/distributed.net
LIBDIR=		${PREFIX}/etc/rc.d

CLIENTUSER=	dnetc
CLIENTGROUP=	${CLIENTUSER}

SBINMODE=	700
BINMODE=	700

MAN1=		dnetc.1

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
	${INSTALL} -c -m 644 -o ${CLIENTUSER} -g ${CLIENTGROUP} ${WRKDIR}/dnetc.ini ${BINDIR}/dnetc.ini.default
.if !exists(${BINDIR}/dnetc.ini)
	@echo ""
	@echo ""
	@echo ""
	@echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@echo "! REMEMBER REMEMBER REMEMBER REMEMBER REMEMBER REMEMBER REMEMBER REMEMBER !"
	@echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@echo "           Don't forget to run '${BINDIR}/dnetc -config'                  "
	@echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@echo ""
	@echo ""
	@echo ""
	${INSTALL} -c -m 644 -o ${CLIENTUSER} -g ${CLIENTGROUP} ${WRKDIR}/dnetc.ini ${BINDIR}
.endif

.include <bsd.port.post.mk>
