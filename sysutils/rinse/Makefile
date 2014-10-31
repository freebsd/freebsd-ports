# $FreeBSD$

PORTNAME=	rinse
PORTVERSION=	3.0.4
CATEGORIES=	sysutils
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	jbeich@vfemail.net
COMMENT=	Install RPM-based system into a directory

LICENSE=	ARTPERL10

RUN_DEPENDS=	p5-Term-Size>0:${PORTSDIR}/devel/p5-Term-Size \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww

NO_ARCH=	yes
NO_BUILD=	yes
USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	bin/* tests/*
MAKE_ARGS=	PREFIX="${STAGEDIR}${PREFIX}" VERSION=${DISTVERSION}
DATADIR=	${PREFIX}/lib/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	requires linuxulator to register rpms

.include <bsd.port.pre.mk>

.if ${OPSYS} == DragonFly
IGNORE=		requires linuxulator to register rpms
.endif

post-extract:
	${MV} ${WRKSRC}/etc/rinse.conf ${WRKSRC}/etc/rinse.conf.sample

post-patch:
	${REINPLACE_CMD} -e 's,/usr,,g' \
		-e 's,/share/man,/man,g' \
		-e '/cache/s/PREFIX/DESTDIR/' \
		-e '/^include VERSION/d' \
		-e '/scripts\.common/s/*/&.sh/' \
		-e 's/\.conf/&.sample/' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' \
		-e 's,/usr/lib,${PREFIX}/lib,g' \
		${WRKSRC}/bin/${PORTNAME} \
		${WRKSRC}/misc/${PORTNAME}
# mount flags and /dev are different, drop duplicates and add missing
	${REINPLACE_CMD} -e 's,-o bind $$i,-t lin$${i#/}fs none,' \
		${WRKSRC}/scripts.common/15-mount-proc.sh
	${REINPLACE_CMD} -Ee 's/sed -i/& ""/' \
		-e '/mknod.*dev/d' \
		-e '/chroot.*MAKEDEV/d' \
		-e '/-o bind.*(proc|sys)/d' \
		-e '/umount.*proc/ { p; s/proc/dev/p; \
		 s/dev/sys/; N; /(.*)\n\1/!P; g; }' \
		${WRKSRC}/scripts/*/post-install.sh

.include <bsd.port.post.mk>
