# $FreeBSD$

PREFIX?=	/usr/X11R6
PLUGIN_DIR?=	${PREFIX}/libexec/gkrellm2/plugins

GKRELLM_INCLUDE=-I${PREFIX}/include

GTK_CONFIG=	pkg-config gtk+-2.0
GTK_CFLAGS=	`${GTK_CONFIG} --cflags`

CFLAGS+=	-Wall -fPIC ${GTK_CFLAGS} ${GKRELLM_INCLUDE}

INSTALL_PROGRAM?=${INSTALL} -s

all:		gkfreq.so

gkfreq.so:	gkfreq.o
	${CC} -Wall -shared -o gkfreq.so gkfreq.o

install:	gkfreq.so
	${INSTALL_PROGRAM} gkfreq.so ${PLUGIN_DIR}

clean:
	rm -f *.o core *.so* *.bak *~
