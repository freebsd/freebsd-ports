PORTNAME=	rlpr
PORTVERSION=	2.06
PORTREVISION=	2
CATEGORIES=	print net
MASTER_SITES=	http://fossies.org/unix/misc/old/	\
		http://linuxfocus.org/~guido/	\
		http://truffula.com/rlpr/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Send print jobs to lpd servers anywhere on a network

LICENSE=	GPLv2

USES=		cpe
GNU_CONFIGURE=	yes
# rlpr supports gettext/libintl, but does not currently come with ANY
# translation .po files. When this changes, it would make sense to
# enable the use of gettext in this port:
#USES+=	gettext
#CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include" LDFLAGS="-L${PREFIX}/lib -lintl"
CONFIGURE_ARGS=	--disable-nls --without-catgets
PLIST_FILES=	bin/rlpr bin/rlpq bin/rlprm bin/rlprd

post-patch:
	# Replacing references to /etc/rlprrc to ${PREFIX}/etc/rlprrc
	${REINPLACE_CMD} -e 's%/etc/rlprrc%${PREFIX}/etc/rlprrc%g' \
		${WRKSRC}/src/rlprrc.h \
		`${GREP} -Fl /etc/rlprrc ${WRKSRC}/man/*.[0-9n]`

post-install:
	# Making the installed binaries suid,\
		      for the remote lpds to talk to them
	${CHMOD} 4555 ${STAGEDIR}${PREFIX}/bin/rlpq	\
		${STAGEDIR}${PREFIX}/bin/rlpr	\
		${STAGEDIR}${PREFIX}/bin/rlprm

PLIST_FILES+=	man/man1/rlpq.1.gz man/man1/rlpr.1.gz man/man1/rlprm.1.gz \
		man/man5/rlprrc.5.gz man/man8/rlprd.8.gz

.include <bsd.port.mk>
