# Created by: Marco Broeder <marco.broeder@gmx.eu>
# $FreeBSD$

PORTNAME=	trojita
PORTVERSION=	0.3.93
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/src/

MAINTAINER=	marco.broeder@gmx.eu
COMMENT=	Fast cross-platform Qt IMAP e-mail client

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

MAKE_JOBS_SAFE=	yes

USE_BZIP2=	yes

USE_QT4=	linguist_build moc_build qmake_build rcc_build \
		uic_build sql-sqlite3 webkit

HAS_CONFIGURE=	yes
INSTALLS_ICONS=	yes
NO_INSTALL_MANPAGES=	yes

do-configure:
	cd ${WRKSRC} && ${QMAKE} ${QMAKEFLAGS} PREFIX=${PREFIX} \
		CONFIG+="release disable_tests" ${PORTNAME}.pro

.include <bsd.port.mk>
