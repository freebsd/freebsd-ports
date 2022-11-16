CXXFLAGS+=	-std=c++17 -Wall -Wextra
CPPFLAGS+=	-Imisc -I$(LOCALBASE)/include
LIBS!=		pkg-config --libs mysqlclient
LIBS+=		-lz

misc_OBJS=	misc/bt_misc.o \
		misc/database.o \
		misc/sha1.o \
		misc/socket.o \
		misc/sql_query.o \
		misc/xcc_z.o

tracker_OBJS=	Tracker/config.o \
		Tracker/connection.o \
		Tracker/epoll.o \
		Tracker/tracker.o \
		Tracker/tracker_input.o \
		Tracker/transaction.o

CCACHE!=	command -v ccache

.cpp.o:
	$(CCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $<

xbt_tracker: $(misc_OBJS) $(tracker_OBJS)
	$(CXX) $(LDFLAGS) -o $@ $>$^ $(LIBS)

all: xbt_tracker

.PHONY: all
