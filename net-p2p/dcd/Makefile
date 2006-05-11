# New ports collection makefile for:	dcd
# Date created:				14 May 2005
# Whom:					Aleksandr S. Goncharov <mraleks@bk.ru>
#
# $FreeBSD$
#

PORTNAME=	dcd
PORTVERSION=	0.6.5
CATEGORIES=	net-p2p
MASTER_SITES=	http://www.dc.ds.pg.gda.pl/download/sources/stable/

MAINTAINER=	mraleks@bk.ru
COMMENT=	Direct Connect Hub clone for Unix

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_RC_SUBR=	dcd.sh

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"

MAN8=		dcd.8 dcd.console.8
MANLANG=	"" pl.ISO8859-2

CONF_FILES=	console.allow dcd.banned dcd.conf dcd.motd dcd.penalties \
		dcd.rules dcd.users dcd.welcome nicks.allow

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	CONF_FILES="${CONF_FILES}" CONF_DIR="${PREFIX}/etc/dcd"

.include <bsd.port.pre.mk>

post-patch:
.for f in dcd dcd.console
	@${MV} ${WRKSRC}/doc/${f}.2 ${WRKSRC}/doc/${f}.8
	@${MV} ${WRKSRC}/doc/pl/${f}.1 ${WRKSRC}/doc/pl/${f}.8
.endfor

.for d in doc doc/pl
.  for f in dcd.8 dcd.console.8
	@${REINPLACE_CMD} -e \
		's|/usr/local|${PREFIX}|g; \
		 s|^\(\.TH .*\)"[12]"|\1"8"|; \
		 s|([12])|(8)|' ${WRKSRC}/${d}/${f}
.  endfor
	@${REINPLACE_CMD} -e 's|man[12]|man8|g; s|\.[12]|.8|g; s|[12]\*|8*|g' \
		${WRKSRC}/${d}/Makefile.in
.endfor

	@${REINPLACE_CMD} -e 's|$$(mandir)/man8|$$(mandir)/pl.ISO8859-2/man8|' \
		${WRKSRC}/doc/pl/Makefile.in

.for f in ${CONF_FILES}
	@${MV} ${WRKSRC}/conf/${f} ${WRKSRC}/conf/${f}.default
	@${REINPLACE_CMD} -e 's|${f}|${f}.default|g' ${WRKSRC}/conf/Makefile.in
.endfor
	@${MV} ${WRKSRC}/conf/dcd.conf.in ${WRKSRC}/conf/dcd.conf.default.in
	@${REINPLACE_CMD} -e 's|\(dcd\.conf\)|\1.default|g' ${WRKSRC}/configure

	@${REINPLACE_CMD} -e 's|-O2||g; s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
