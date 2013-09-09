# Created by: Hakisho Nukama <nukama@gmail.com>
# $FreeBSD$

PORTNAME=	checkbashisms
PORTVERSION=	2.12.6
CATEGORIES=	textproc perl5
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/d/devscripts/
DISTNAME=	devscripts_${PORTVERSION}

MAINTAINER=	nukama+maintainer@gmail.com
COMMENT=	Debian script that checks for bash-isms

LICENSE=	GPLv2

NO_BUILD=	yes
USE_PERL5=	run
USES=		perl5
WRKSRC=		${WRKDIR}/devscripts-${PORTVERSION}

MAN1=		checkbashisms.1
PLIST_FILES=	bin/checkbashisms

post-patch:
	@${REINPLACE_CMD} -e 's|###VERSION###|${PORTVERSION}|' ${WRKSRC}/scripts/checkbashisms.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/checkbashisms.pl ${PREFIX}/bin/checkbashisms
	${INSTALL_MAN} ${WRKSRC}/scripts/checkbashisms.1 ${MANPREFIX}/man/man1/

.include <bsd.port.mk>
