# New ports collection makefile for:    networker-client602
# Date created:         Sat Oct 27 09:48:19 PDT 2001
# Whom:                 Matthew Jacob <mjacob@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	nwclient
PORTVERSION=	6.0.2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.feral.com/pub/networker/freebsd/freebsd_40/
ARCH!=		uname -m
DISTNAME=	nwclient-${PORTVERSION}-freebsd-${ARCH}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

NO_BUILD=	yes

post-patch:
	@sed -e "s,^ROOTDIR.*$$,ROOTDIR=${PREFIX}," ${WRKSRC}/networker.sh >\
		${WRKDIR}/NWCTMP && chmod +w ${WRKSRC}/networker.sh && \
		cp ${WRKDIR}/NWCTMP ${WRKSRC}/networker.sh && \
		chmod -w ${WRKSRC}/networker.sh

do-install:
	@mkdir -p /usr/local/nsr/bin /usr/local/man/man8 /usr/local/etc/rc.d
	@cd ${WRKSRC} && tar cf - gls | \
		(cd /usr/local/nsr && tar --unlink -xpf -)
	@cd ${WRKSRC}/${ARCH} && tar cf - . | \
		(cd /usr/local/nsr/bin && tar --unlink -xpf -)
	@cd ${WRKSRC} && tar cf - networker.sh | \
		(cd /usr/local/etc/rc.d  && tar --unlink -xpf -)
	@cd ${WRKSRC}/catman && tar cf - *.1 | \
		(cd /usr/local/man/cat1  && tar --unlink -xpf -)
	@cd ${WRKSRC}/catman && tar cf - *.3 | \
		(cd /usr/local/man/cat3  && tar --unlink -xpf -)
	@cd ${WRKSRC}/catman && tar cf - *.5 | \
		(cd /usr/local/man/cat5  && tar --unlink -xpf -)
	@cd ${WRKSRC}/catman && tar cf - *.8 | \
		(cd /usr/local/man/cat8  && tar --unlink -xpf -)

post-install:
	@sed -e "s,ROOTDIR,${PREFIX}," < ${PKGMESSAGE}
	@cd / && rm -f nsr && ln -s ${PREFIX}/nsr

pre-deinstall:
	rm -f /nsr

.include <bsd.port.mk>
