# New ports collection makefile for:    dnetc
# Date created:         26 Dec 1999
# Whom:                 dbaker
#
# $FreeBSD$
#

PORTNAME=	dnetc
PORTVERSION=	2.8010.462
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

.if ${OSVERSION} < 220000
BROKEN=		"dnetc is not available for your version of FreeBSD.  Please upgrade."
.elif ${OSVERSION} < 300000
BROKEN=		"No version is currently available for your system.  Please try again later."
.endif

.if exists(${PREFIX}/distributed.net/rc5des)
BROKEN=		"rc5des/dnetc conflict: Please deinstall all rc5des ports/packages first."
.endif

MAINTAINER=	dbaker@distributed.net

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

BINDIR=		${PREFIX}/distributed.net
LIBDIR=		${PREFIX}/etc/rc.d

CLIENTUID=	nobody
CLIENTGID=	daemon

SBINMODE=	700
BINMODE=	700

MAN1=		dnetc.1

do-configure:
	if [ ! -f ${PREFIX}/dnetc.ini ]; then \
		${INSTALL} -c -m 644 ${FILESDIR}/dnetc.ini ${WRKSRC}; \
	fi

do-install:
	if [ ! -d ${BINDIR} ]; then \
		${MKDIR} ${BINDIR}; \
	fi

	${INSTALL} -c -m ${SBINMODE} -o ${CLIENTUID} -g ${CLIENTGID} ${WRKSRC}/dnetc ${BINDIR}

	${SED} s#CHANGETHIS#${BINDIR}# < ${FILESDIR}/dnetc.sh > ${WRKSRC}/dnetc.sh.pathnames
	${INSTALL} -c -m ${SBINMODE} ${WRKSRC}/dnetc.sh.pathnames ${LIBDIR}/dnetc.sh

	${INSTALL_DATA} ${FILESDIR}/INFO ${BINDIR}

	${CHOWN} ${CLIENTUID}:${CLIENTGID} ${BINDIR}
	${CHMOD} 775 ${BINDIR}

	if [ ! -f ${BINDIR}/dnetc.sh ]; then \
		${LN} -s ${LIBDIR}/dnetc.sh ${BINDIR}/dnetc.sh; \
	fi

	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1

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
	${INSTALL} -c -m 644 -o ${CLIENTUID} -g ${CLIENTGID} ${WRKDIR}/dnetc.ini ${BINDIR}
.endif

.include <bsd.port.post.mk>
