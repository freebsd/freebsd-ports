X11BASE		?=	/usr/X11R6
INCDIR		=	-I$(X11BASE)/include
LIBDIR		=	-L$(X11BASE)/lib
LIBS		=	-lX11 -lXmu
OBJS		=	remote.o
CFLAGS		+=	-DSTANDALONE -g $(INCDIR)
PREFIX		?=	/usr/local
BSD_INSTALL_PROGRAM ?=	/usr/bin/install -c -s

BINARY		=	netscape-remote

all: remote

remote: $(OBJS)
	$(CC) $(CFLAGS) $(LIBDIR) $(LIBS) -o $(BINARY) $(OBJS)

install: all
	$(BSD_INSTALL_PROGRAM) $(BINARY) $(PREFIX)/bin

clean:
	for i in $(OBJS); do rm -f $$i; done
	rm -f $(BINARY)
