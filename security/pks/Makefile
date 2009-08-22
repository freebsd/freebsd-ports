# New ports collection makefile for:	pks
# Date created:		15 Jan 2001
# Whom:			kris@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	pks
PORTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES=	security www
MASTER_SITES=	SF

MAINTAINER=	gtodd@bellanet.org
COMMENT=	PGP Public Key Server

USE_BDB=	yes
WANT_BDB_VER=	2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/pks --localstatedir=/var/pks \
		--sysconfdir=${EXAMPLESDIR} \
		--libdir=${LOCALBASE}/lib --with-libwrap
CFLAGS+=	-I${BDB_INCLUDE_DIR}
MAKE_ENV+=	LDFLAGS=-L${LOCALBASE}/lib SUBDIRS=

USE_RC_SUBR=	pksd.sh
MAN5=		pksd.conf.5
MAN8=		pks-intro.8 pksclient.8 pksd.8 pksdctl.8
SUB_FILES=	pkg-message pkg-deinstall

# remove embedded sleepycat, remove associated build commands, make
# the build use the headers and libraries from the db2 port
post-patch:
	${RM} -rf ${WRKSRC}/db2-sleepycat
	${REINPLACE_CMD} 's|SUBDIRS =.*|SUBDIRS =|; \
			  s|LIBDB =.*|LIBDB = -L${LOCALBASE}/lib -l${BDB_LIB_NAME}|; \
			  s|DBDIR =.*|DBDIR = ${BDB_INCLUDE_DIR}|' \
			  ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/pksd.conf ${PREFIX}/etc/pksd.conf.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/pks_help.en ${WRKSRC}/pks_help.es ${WRKSRC}/pks_help.fr \
       	${WRKSRC}/pks_help.cz ${WRKSRC}/pks_help.de ${WRKSRC}/pks_help.ja \
	${WRKSRC}/mail_intro ${DOCSDIR}
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
