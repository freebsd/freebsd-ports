# New ports collection makefile for:	cyphesis
# Date created:				02 Oct 2005
# Whom:					Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cyphesis
PORTVERSION=	0.5.6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=worldforge

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A server for WorldForge games

LIB_DEPENDS=	Atlas-0.6.1:${PORTSDIR}/devel/atlas-devel \
		varconf-1.0.6:${PORTSDIR}/devel/varconf \
		wfmath-0.3.3:${PORTSDIR}/math/wfmath \
		mercator-0.2.4:${PORTSDIR}/devel/mercator \
		skstream-0.3.3:${PORTSDIR}/net/skstream \
		gcrypt.13:${PORTSDIR}/security/libgcrypt

CONFIGURE_ARGS=	--with-python=${LOCALBASE}

GNU_CONFIGURE=	YES
INSTALLS_SHLIB=	YES
USE_GCC=	3.4
USE_BZIP2=	YES
USE_PGSQL=	YES
USE_PYTHON=	YES
USE_GNOME=	gnomehack

MAN1=		cyclient.1 cycmd.1 cyphesis.1 cyphesis-tools.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		Does not compile
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| install-dist_docDATA | |g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's| install-confbackupDATA | |g' ${WRKSRC}/data/Makefile.in
	@${REINPLACE_CMD} -e 's|-lpython|${PTHREAD_LIBS} &|' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e 's|$$(datadir)/cyphesis|${DATADIR}|g'
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|<stdint.h>|<inttypes.h>|' \
		${WRKSRC}/server/CommMDNSPublisher.h
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/conf
.for docfile in README COPYING AUTHORS THANKS NEWS ChangeLog TODO
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.for docfile in acorn.xml basic.xml cyphesis.vconf mason.xml werewolf.xml
	@${INSTALL_DATA} ${WRKSRC}/data/${docfile} ${DOCSDIR}/conf
.endfor
.endif

.include <bsd.port.post.mk>
