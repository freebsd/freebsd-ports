# New ports collection makefile for:	mailsync
# Date created:		03 Feb 2003
# Whom:			Maxim Tulyuk <mt@primats.org.ua>
#
# $FreeBSD$
#

PORTNAME=	mailsync
PORTVERSION=	5.2.1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	mt@primats.org.ua
COMMENT=	Mailsync is a way of keeping a collection of mailboxes synchronized

LIB_DEPENDS=	c-client4.8:${PORTSDIR}/mail/cclient

BROKEN=		Configure fails
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_GCC=	2.95+
#CONFIGURE_ARGS=	CC=gcc --exec-prefix=${PREFIX}
#CONFIGURE_ARGS+=	--exec-prefix=${PREFIX} \
#		--includedir="${PREFIX}/include ${PREFIX}/include/c-client"
#CONFIGURE_ENV+=	CPPFLAGS="-I${PREFIX}/include/c-client"

USE_AUTOMAKE_VER=	19
USE_AUTOCONF_VER=	259
USE_AUTOHEADER_VER=	259
USE_REINPLACE=	yes

pre-patch:
	@${REINPLACE_CMD} -e 's|^aclocal|${ACLOCAL}|; \
		s|^autoconf|${AUTOCONF}|; s|automake|${AUTOMAKE}|; \
		s|^autoheader|${AUTOHEADER}|; s|678|9|' ${WRKSRC}/autogen.sh

run-autotools:

do-configure:
	cd ${WRKSRC} && ${SH} autogen.sh --exec-prefix=${PREFIX}

MAN1=		mailsync.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/mailsync ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/mailsync.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS COPYING NEWS README \
		THANKS TODO ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ABSTRACT HACKING \
		mail_open_close_flowchart.dia \
		mail_open_close_flowchart.svg \
		mail_open_close_flowchart2.svg ${DOCSDIR}
.endif
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/examples/mailsync ${EXAMPLESDIR}

.include <bsd.port.mk>
