PORTNAME=	procmap
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	sysutils
DISTFILES=	#empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Print the contents of a procfs map file

USES=		uidfix
MAKEFILE=	/usr/share/mk/bsd.prog.mk
MAKE_ENV+=	BINDIR=${PREFIX}/bin \
		MAN8=procmap.8 \
		MANDIR=${PREFIX}/share/man/man \
		PROG=procmap

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/procmap \
		share/man/man8/${PORTNAME}.8.gz

procmap_files:=	procmap.c procmap.8

post-extract:
	cd ${FILESDIR} ; \
		${CP} -p ${procmap_files} ${WRKSRC}

.include <bsd.port.mk>
