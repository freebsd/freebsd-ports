# $FreeBSD$

PKGNAMESUFFIX=	-glx

COMMENT=	VAAPI wrapper for GLX

MASTERDIR=	${.CURDIR}/../libva

OPTIONS_SLAVE=	GLX X11
OPTIONS_EXCLUDE=WAYLAND

post-install:	slave-post-install
slave-post-install:
	@${REINPLACE_CMD} '/glx/!s/^/@comment /' ${TMPPLIST}

.include "${MASTERDIR}/Makefile"
