# New ports collection makefile for:	harvest
# Date created:		Fri Mar  1 19:43:52 MET 1996
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	harvest
PORTVERSION=	1.8.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_BZIP2=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL} \
		--prefix=${PREFIX}/${PORTNAME} \
		--without-wish 

STRIP=		# none

post-patch:
	@${GREP} -lR "malloc.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'

post-install:
.for file in bin/broker bin/gather lib/broker/BrokerRestart \
	lib/broker/agrep lib/broker/brkclient lib/broker/dumpregistry \
	lib/broker/glimpse lib/broker/glimpseindex.bin \
	lib/broker/glimpseserver lib/broker/swish lib/ftpget \
	lib/gatherer/HTML-lax.sum lib/gatherer/HTMLurls lib/gatherer/catdoc \
	lib/gatherer/cksoif lib/gatherer/cleandb lib/gatherer/consoldb \
	lib/gatherer/dvi2tty lib/gatherer/enum lib/gatherer/essence \
	lib/gatherer/expiredb lib/gatherer/fileenum lib/gatherer/ftpenum \
	lib/gatherer/gatherd lib/gatherer/gdbmutil lib/gatherer/gifinfo \
	lib/gatherer/gopherenum-breadth lib/gatherer/gopherenum-depth \
	lib/gatherer/hexbin lib/gatherer/httpenum-breadth \
	lib/gatherer/httpenum-depth lib/gatherer/mergedb \
	lib/gatherer/mkindex lib/gatherer/newsenum lib/gatherer/prepurls \
	lib/gatherer/print-attr lib/gatherer/print-c-comments \
	lib/gatherer/ps2txt-2.1 lib/gatherer/pstext lib/gatherer/rast \
	lib/gatherer/rmbinary lib/gatherer/rtf2html lib/gatherer/sgmls \
	lib/gatherer/sgmlsasp lib/gatherer/skim lib/gatherer/staturl \
	lib/gatherer/template2db lib/gatherer/wp2x lib/gatherer/xls2csv \
	lib/md5 lib/urlget lib/urlpurge
	@${STRIP_CMD} ${PREFIX}/${PORTNAME}/${file}
.endfor

.include <bsd.port.mk>
