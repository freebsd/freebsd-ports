# ports collection Makefile for: cone
# Whom:		Matthias Andree <matthias.andree@gmx.de>
# Date created:	2003-06-19
#
# $FreeBSD$
#

PORTNAME=	cone
PORTVERSION=	0.58
CATEGORIES=	mail
# This is for beta versions, leave it in please:
#MASTER_SITES=	http://www.courier-mta.org/beta/${PORTNAME}/
# This is for release versions, leave it in please:
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	courier

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console based mail client with POP3/IMAP/SMAP support

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		aspell.15:${PORTSDIR}/textproc/aspell \
		ncurses.5:${PORTSDIR}/devel/ncurses \
		fam.0:${PORTSDIR}/devel/fam
BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GETTEXT=	yes
USE_ICONV=	yes

USE_BZIP2=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	-C --without-db --prefix=${PREFIX} --exec-prefix=${PREFIX}

CONFIGURE_ENV=	REHASH="${PERL} ${SCRIPTDIR}/c_rehash" LDFLAGS=-L${LOCALBASE}/lib \
		CPPFLAGS=-I${LOCALBASE}/include
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAN1=		cone.1 leaf.1 mailtool.1
INSTALL_TARGET=	install-strip

post-install:
		${INSTALL_SCRIPT} ${WRKSRC}/sysconftool ${PREFIX}/sbin/cone-sysconftool
		PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PORTNAME} POST-INSTALL
		${RM} -f ${PREFIX}/share/cone/rootcerts/.0
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_MAN} ${WRKSRC}/ChangeLog ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		"does not build on FreeBSD versions before FreeBSD 5"
.endif

.include <bsd.port.post.mk>
