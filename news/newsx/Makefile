# New ports collection makefile for:	newsx
# Date created: 10th February, 2001
# Whom:		Thierry Thomas <tthomas@mail.dotcom.fr>
#
# $FreeBSD$
#

PORTNAME=	newsx
PORTVERSION=	1.4
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.kvaleberg.com/pub/

MAINTAINER=	tthomas@mail.dotcom.fr

BUILD_DEPENDS=	${LOCALBASE}/news/lib/libinn.a:${PORTSDIR}/news/inn:${hdr_dir}

hdr_dir=	${LOCALBASE}/news/include

post-extract:
	@${ECHO} "*********************************************************"
	@${ECHO} "If this step fails, then you probably don't have made inn"
	@${ECHO} "Go to ${PORTSDIR}/news/inn, and then make it (no need to"
	@${ECHO} "make install again if inn is already installed)."
	@${ECHO} "*********************************************************"
	${CP} ${hdr_dir}/storage.h	${WRKSRC}/lib
	${CP} ${hdr_dir}/config.h	${WRKSRC}/lib
	${CP} ${hdr_dir}/libinn.h	${WRKSRC}/src
	${CP} ${hdr_dir}/libinn.h	${WRKSRC}/dbz
	${CP} ${hdr_dir}/clibrary.h	${WRKSRC}/dbz

# Remark: newsx does not really requires inn, but this port has specially
# been built to run with inn 2.3x.
pre-configure:
	@${ECHO} "*********************************************************"
	@${ECHO} "If the configure step fails, then you probably don't have"
	@${ECHO} "a news server package installed.  Try installing INN from"
	@${ECHO} "${PORTSDIR}/news/inn, and then try building this port"
	@${ECHO} "again."
	@${ECHO} "*********************************************************"

post-configure:
	@${PERL} -pi -e "s:^LIBS = :LIBS = -L${LOCALBASE}/news/lib -linn:g" \
	${WRKSRC}/test/Makefile

#GNU_CONFIGURE=	yes
USE_AUTOCONF= yes

MAN1=	newsq.1
MAN5=	newsx.conf.5 in.hosts.5
MAN8=	newsx.8

.include <bsd.port.mk>
