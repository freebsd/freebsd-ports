PORTNAME=	amanda-perl-wrapper
PORTVERSION=	1.01
CATEGORIES=	misc perl5
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl wrapper to use with Amanda (with libthr.so.* linked)

USES=		perl5
USE_PERL5=	run

NO_WRKSUBDIR=	yes
SUB_FILES=	perl-amanda.c
SUB_LIST=	PREFIX=${LOCALBASE}
PLIST_FILES=	bin/perl-amanda

do-fetch:
	@${DO_NADA}

do-build:
	cd ${WRKSRC} && ${CC} -o perl-amanda ${WRKDIR}/perl-amanda.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/perl-amanda ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.pre.mk>

LIBTHR!=	${LS} /lib/libthr.so.* | ${TAIL} -1
SUB_LIST+=	LIBTHR=${LIBTHR}

.include <bsd.port.post.mk>
